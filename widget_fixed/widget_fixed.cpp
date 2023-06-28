#include "widget_fixed.h"
#include "ui_widget_fixed.h"
#include"adddialog.h"
#include"head_fixed.h"
Widget_fixed::Widget_fixed(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget_fixed)
{
    ui->setupUi(this);


    //这个是addButton粘贴图片
    QPixmap pixmap("D:\\qt things\\try111\\add.jpg");
    QPixmap pix = pixmap.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);//平滑算法，设置了图片规格
    ui->addButton->setIcon(QIcon(pix));//粘贴图片
    //Qt::FastTransformation：快速算法，可能会导致图片质量较差。
   //Qt::SmoothTransformation：平滑算法，可以获得更好的图片质量，但速度较慢。



    //打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/qt things/widget_fixed/fix.sqlite");
    if (!db.open()) {
        qDebug() << "Failed to connect to database!";
    } else {
        qDebug() << "Connected to database!";
    }
    //创建表单item_fixed1，用来存放未被勾选的数值
        QSqlQuery query_1;
        QString sql_create1=QString("CREATE TABLE IF NOT EXISTS item_fixed1 (name TEXT, time TEXT,timer TEXT,checked TEXT)");
        if (!query_1.exec(sql_create1)) {
             qDebug() << "Failed to execute query:" << query_1.lastError().text();
        }

        //创建表单item_fixed2,用来存放已被勾选的数值
        QSqlQuery query_2;
        QString sql_create2=QString("CREATE TABLE IF NOT EXISTS item_fixed2 (name TEXT, time TEXT,timer TEXT,checked TEXT)");
        if (!query_2.exec(sql_create2)) {
             qDebug() << "Failed to execute query:" << query_2.lastError().text();
        }


    //读取数据库的数据

    loadItems();

    //fixed1中的行设置定时器
    setTimer();

}



void Widget_fixed::clearData(){
    // 清空所有项目布局
    QLayoutItem *item;
    while ((item = ui->widgetVLayout_fixed->takeAt(0))) {
        QLayout *layout = item->layout();
        if (layout) {
            // 清除子布局中的控件
            QLayoutItem *subItem;
            while ((subItem = layout->takeAt(0))) {
                if (subItem->widget()) {
                    delete subItem->widget();
                }
                delete subItem;
            }
        }
        delete item;
    }

}


//清空定时器
void Widget_fixed::clearTimer(){
    // 停止并删除所有定时器
    for (int i = 0; i < timerEvents.size(); i++) {
        timerEvents.at(i).timer->stop();
        delete timerEvents.at(i).timer;
    }

    // 清空列表
    timerEvents.clear();
}

//设置定时器（只设置未勾选的项)
void Widget_fixed::setTimer(){
    QSqlQuery query;
    query.exec("SELECT * FROM item_fixed1");
    while (query.next()) {
        QString datetime_2 = query.value("time").toString();
        QDateTime dateTimer = QDateTime::fromString(datetime_2);
        QVariant isTimerVar=query.value("timer");
        bool isTimer=isTimerVar.toBool();
        QDateTime currentDateTime = QDateTime::currentDateTime();

        //设置时间和系统时间的差
        int msecs = currentDateTime.msecsTo(dateTimer);

        if (msecs < 0) {
            // 如果设置的时间已经过去，直接继续循环
            continue;
        }



        //如果设置了i自动提醒
        if(isTimer){
        // 新建一个 QTimer 定时器
        QTimer* messageTimer = new QTimer(this);
        connect(messageTimer, &QTimer::timeout, this, &Widget_fixed::messageTimeout);

        // 设定定时器开始时间
        messageTimer->start(msecs);

        // 创建一个 TimeEvent 结构体，用于存储定时器对象和事件名称
        QString name = query.value("name").toString();
        TimeEvent timeEvent = { messageTimer, name };

        // 将 TimeEvent 对象存储到 timerEvents 列表中
        timerEvents.append(timeEvent);
    }
}
}

//读取数据
void Widget_fixed::loadItems()
{

    // 从数据库中读取项目并显示
    QSqlQuery query;

    //先显示未勾选数据
    if (query.exec("SELECT * FROM item_fixed1")) {

        while (query.next()) {
            QString fixedname = query.value("name").toString();
            QString datetime = query.value("time").toString();
            QString ischecked=query.value("checked").toString();

            //在界面上显示读取的数据
            auto *HLayout=new QHBoxLayout;
            auto *label = new QLabel(fixedname+" "+datetime, this);
            HLayout->addWidget(label);

            //给每一行设定属性，标记是否被勾选
            HLayout->setProperty("ischecked", ischecked);

            //把新的水平布局添加到ui上的垂直布局
            ui->widgetVLayout_fixed->addLayout(HLayout);
        }

    } else {
        qDebug() << "Failed to query data!";
    }

    for(int i = 0; i < ui->widgetVLayout_fixed->count(); ++i) {
        // 获取水平布局
        QLayoutItem* item = ui->widgetVLayout_fixed->itemAt(i);
       QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());
        if (hLayout) {

            // 创建一个新的勾选按钮并将其添加到水平布局中
            QCheckBox *chooseBox = new QCheckBox;
            QString ischecked = hLayout->property("ischecked").toString();

            connect(chooseBox, &QCheckBox::stateChanged, this, &Widget_fixed::onchooseButtonClicked);
            chooseBox->setProperty("row_2", i);//给按钮设置属性，属性名称为row，属性值为i

            hLayout->insertWidget(0,chooseBox);
        }
    }


    //读取已勾选表的信息
    QSqlQuery query_2;
    if (query_2.exec("SELECT * FROM item_fixed2")) {

        while (query_2.next()) {
            QString fixedname = query_2.value("name").toString();
            QString datetime = query_2.value("time").toString();
            QString ischecked=query_2.value("checked").toString();

            //在界面上显示读取的数据
            auto *HLayout=new QHBoxLayout;
            auto *label = new QLabel(fixedname+" "+datetime, this);
            HLayout->addWidget(label);
            HLayout->setProperty("ischecked", ischecked);

            //添加一个摆设勾选框，表示已勾选
            QCheckBox *chooseBox1 = new QCheckBox;

               { chooseBox1->setChecked(true);
                chooseBox1->setEnabled(false);}
           HLayout->insertWidget(0,chooseBox1);

            //把新的水平布局添加到ui上的垂直布局
            ui->widgetVLayout_fixed->addLayout(HLayout);
        }

    } else {
        qDebug() << "Failed to query data!";
    }
}

Widget_fixed::~Widget_fixed()
{
    delete ui;

}


void Widget_fixed::on_addButton_clicked()
{
    //创建了对话框用来添加项目
    addDialog *dialog=new addDialog;
    dialog->setWindowTitle("添加项目");
    //接收对话框传来的点击确认的信号，清空布局和定时器，然后调用定时器函数和读取数据
    connect(dialog,&addDialog::nameEntered,this,&Widget_fixed::clearTimer);
    connect(dialog,&addDialog::nameEntered,this,&Widget_fixed::setTimer);

    connect(dialog,&addDialog::nameEntered,this,&Widget_fixed::clearData);
    connect(dialog,&addDialog::nameEntered,this,&Widget_fixed::loadItems);
    dialog->show();
}



void Widget_fixed::on_manageButton_clicked()
{

       //切换标志以指示我们是否处于删除模式
       isDeleteMode = !isDeleteMode;
       // 启用添加按钮
       ui->addButton->setEnabled(true);


       // 如果处于删除模式，则为现有控件添加删除按钮
       if (isDeleteMode) {

           int j=0;
           // 遍历每个现有的水平布局并添加删除按钮
           for(int i = 0; i < ui->widgetVLayout_fixed->count(); ++i) {
               // 获取水平布局
               QLayoutItem* item = ui->widgetVLayout_fixed->itemAt(i);
               QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());

               if (hLayout) {
                   // 创建一个新的删除按钮并将其添加到水平布局中
                   QString ischecked=hLayout->property("ischecked").toString();
                   QPushButton *deleteButton = new QPushButton("删除");
                   connect(deleteButton, &QPushButton::clicked, this, &Widget_fixed::onDeleteButtonClicked);

                   //给按钮设置属性，属性名称为row，用来删除水平布局
                   deleteButton->setProperty("row", i);

                   //给按钮设置属性，属性名称为row——choose,用来索引数据库
                   if(ischecked=="false"){
                       deleteButton->setProperty("row_choose", i);
                       j++;//存储未勾选项的数量
                   }
                   if(ischecked=="true"){
                       deleteButton->setProperty("row_choose", i-j);//使得已勾选项从0开始计算
                       }

                       hLayout->addWidget(deleteButton);
                   }
           }

           // 禁用添加按钮
                  ui->addButton->setDisabled(true);

       }

       // 如果不在删除模式，就将所有删除按钮从布局中移除
       else {
           for(int i = 0; i < ui->widgetVLayout_fixed->count(); ++i) {
               // 获取水平布局
               QLayoutItem* item = ui->widgetVLayout_fixed->itemAt(i);
               QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());


               if (hLayout) {
                   // 遍历每个子布局中的控件并查找指定的删除按钮
                   for (int j = 0; j < hLayout->count(); ++j) {
                       QPushButton *button = dynamic_cast<QPushButton*>(hLayout->itemAt(j)->widget());
                       if (button && button->text() == "删除") {
                           // 找到删除按钮，使用 delete 操作符将其删除
                           delete button;
                           break;
                       }
                   }
               }

           }

      }
}

//按动删除按钮的反应
void Widget_fixed::onDeleteButtonClicked(){
    // 获取发送信号的按钮
       QPushButton *button = qobject_cast<QPushButton*>(sender());
       if (button) {
           // 从按钮的属性中获取行号
           int row = button->property("row").toInt();
           int row_choose = button->property("row_choose").toInt();


           //判断水平布局数量是否为一
           if(ui->widgetVLayout_fixed->count() ==1){
                      //删除所有水平布局
                      QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(ui->widgetVLayout_fixed->itemAt(0)->layout());
                      QLayoutItem* subItem;
                      //删除控件
                      while ((subItem = hLayout->takeAt(0))) {
                      QWidget* widget = subItem->widget();
                      if (widget) {
                          delete widget;
                      }
                      //删除子布局
                      QLayout* childLayout = subItem->layout();
                      if (childLayout) {
                           delete childLayout;
                      }
                           delete subItem;
                  }

                      delete hLayout;
                      ui->widgetVLayout_fixed->removeItem(ui->widgetVLayout_fixed->itemAt(0));

                      //从数据库删除
                      QSqlQuery query;
                      query.exec("DELETE FROM item_fixed1");
                      query.exec("DELETE FROM item_fixed2");

                      //退出删除模式
                      isDeleteMode = !isDeleteMode;
                      // 启用添加按钮
                      ui->addButton->setEnabled(true);
                  }



           //水平布局数量大于一时
           else if (ui->widgetVLayout_fixed->count() > 1 && isDeleteMode) {
           //删除相应水平布局

           // 获取对应的水平布局
           QLayoutItem* item = ui->widgetVLayout_fixed->itemAt(row);
           QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());
           QString ischecked=hLayout->property("ischecked").toString();//判断是否被勾选

               if (hLayout) {              
                   QLayoutItem* subItem;
                   while ((subItem = hLayout->takeAt(0))) {
                   QWidget* widget = subItem->widget();
                   if (widget) {
                       delete widget;
                   }
                   QLayout* childLayout = subItem->layout();
                   if (childLayout) {
                       delete childLayout;
                   }

                   delete subItem;
               }

               // 将水平布局从垂直布局中删除
               ui->widgetVLayout_fixed->removeItem(item);

               // 将水平布局删除
               delete hLayout;
           }

           // 从数据库中删除相应的数据
           QSqlQuery query;
           QString sql;

           if(ischecked=="false"){
               sql = QString("DELETE FROM item_fixed1 WHERE rowid IN (SELECT rowid FROM item_fixed1 LIMIT 1 OFFSET %1)") .arg(row);

               }
           if(ischecked=="true"){
               sql = QString("DELETE FROM item_fixed2 WHERE rowid IN (SELECT rowid FROM item_fixed2 LIMIT 1 OFFSET %1)") .arg(row_choose);}
           query.exec(sql);

           // 更新其他布局的行号，保证行号连续
           int j=0;
           for (int i = 0; i < ui->widgetVLayout_fixed->count(); ++i) {
               QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(ui->widgetVLayout_fixed->itemAt(i)->layout());

               if (hLayout) {
                   // 更新删除按钮的行号属性
                   QPushButton* deleteButton = dynamic_cast<QPushButton*>(hLayout->itemAt(hLayout->count() - 1)->widget());
                   QLayoutItem* item = ui->widgetVLayout_fixed->itemAt(i);
                   QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());
                   QString ischecked1=hLayout->property("ischecked").toString();

                   if (deleteButton) {
                       deleteButton->setProperty("row", i);//给按钮设置属性，属性名称为row，属性值为i

                       if(ischecked1=="false"){
                       deleteButton->setProperty("row_choose", i);//给按钮设置属性，属性名称为row，属性值为i
                       j++;
                       }

                       if(ischecked1=="true"){

                           deleteButton->setProperty("row_choose", i-j);//给按钮设置属性，属性名称为row，属性值为i

                       }
                    }
               }
           }
                   // 更新数据库中的记录
                   if(ischecked=="flase"){
                       for(int i=row;i<j;++i){

                           query.prepare("UPDATE item_fixed1 SET rowid = :rowid WHERE rowid = :old_rowid");
                           query.bindValue(":rowid", i);
                           query.bindValue(":old_rowid", i+1);
                           query.exec();
                       }
                   }

                   if(ischecked=="true"){
                       for(int i=j;i < ui->widgetVLayout_fixed->count(); ++i){
                           query.prepare("UPDATE item_fixed2 SET rowid = :rowid WHERE rowid = :old_rowid");
                           query.bindValue(":rowid", i-j);
                           query.bindValue(":old_rowid", i-j+1);
                           query.exec();
                       }
                   }
           }


       }
}


//定时器提醒
void Widget_fixed::messageTimeout()
{
       // 停止定时器并释放内存
       QTimer* timer = qobject_cast<QTimer*>(sender());
       // 显示提醒对话框
       for (int i = 0; i < timerEvents.size(); ++i) {
           if (timerEvents.at(i).timer == timer) {  // 找到定时器对应的时间事件对象
               QString name = timerEvents.at(i).eventName;  // 获取对应的名称信息
               QMessageBox::information(this, "时间到咯", "It's time for " + name);
               timer->stop();
               messageTimers.removeOne(timer); // 从列表中移除
               timer->deleteLater();           // 释放内存
           }
       }
}

//勾选处理
void Widget_fixed::onchooseButtonClicked(){
    //找到发出信号的勾选框
    QCheckBox *box = qobject_cast<QCheckBox*>(sender());

    QSqlQuery query;

    if (box) {
        // 从按钮的属性中获取行号
        int row_2 = box->property("row_2").toInt();
        qDebug()<<row_2;

        // 编写 SQL 查询语句
        QString sql = QString("SELECT * FROM item_fixed1 LIMIT 1 OFFSET %1").arg(row_2);

        QString name,time,timer;

        int j=0;
        // 找到对应行的数据
        if (query.exec(sql)) {
            // 遍历查询结果的每一行
            if (query.next()) {
                // 在此处处理查询结果
                 name = query.value("name").toString();
                 time = query.value("time").toString();
                 timer= query.value("timer").toString();
                 j++;
            }
            else {
                 qDebug() << "No record found for ROWID=" << row_2;

            }
        }
        else {
            // 在此处处理查询错误
            qDebug() << "Query Error:" << query.lastError().text();
        }


        //删除数据
        if (ui->widgetVLayout_fixed->count() > 1 ) {
            QSqlQuery query;
            QString sql = QString("DELETE FROM item_fixed1 WHERE rowid IN (SELECT rowid FROM item_fixed1 LIMIT 1 OFFSET %1)") .arg(row_2);
            query.exec(sql);

            // 更新其他布局的行号，保证行号连续
            for (int i = row_2; i < ui->widgetVLayout_fixed->count(); ++i) {
             // 更新数据库中的记录，只需要处理未勾选数据库
                query.prepare("UPDATE item_fixed1 SET rowid = :rowid WHERE rowid = :old_rowid");
                query.bindValue(":rowid", i);
                query.bindValue(":old_rowid", i+1);
                query.exec();
             }

        }
        else{
             QSqlQuery query;
             query.exec("DELETE FROM item_fixed1");
        }

        //改变勾选状态
        QString ischeck="true";
        QString sql2 = QString("INSERT INTO item_fixed2 (name, time, timer,checked) VALUES ('%1', '%2', '%3','%4')")
                      .arg(name).arg(time).arg(timer).arg(ischeck);
        if (!query.exec(sql2)) {
             qDebug() << "Failed to execute query:" << query.lastError().text();
        }

        //清屏重绘
        clearData();
        loadItems();
    }

}
