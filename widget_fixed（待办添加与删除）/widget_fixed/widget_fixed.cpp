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


//创建表单item
    QSqlQuery query;
    QString sql1=QString("CREATE TABLE IF NOT EXISTS item (name TEXT, time TEXT)");
    if (!query.exec(sql1)) {
         qDebug() << "Failed to execute query:" << query.lastError().text();
    }
    //读取数据库的数据
    loadItems();

}

void Widget_fixed::loadItems()
{
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

    // 从数据库中读取项目并显示
    QSqlQuery query;
    if (!query.exec("SELECT * FROM item")) {
        QSqlError error = query.lastError();
        qDebug() << "Failed to query data: " << error.text();
    }
    if (query.exec("SELECT * FROM item")) {
        while (query.next()) {
            QString name = query.value("name").toString();
            QString datetime = query.value("time").toString();
            //在界面上显示读取的数据
            auto *HLayout=new QHBoxLayout;
            auto *label = new QLabel(name+" "+datetime, this);
            HLayout->addWidget(label);

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
    //接收对话框传来的点击确认的信号，然后调用onNameEntered
    connect(dialog,&addDialog::nameEntered,this,&Widget_fixed::loadItems);
    dialog->show();
}



void Widget_fixed::on_manageButton_clicked()
{
    // 切换标志以指示我们是否处于删除模式
       isDeleteMode = !isDeleteMode;

       // 如果处于删除模式，则为现有控件添加删除按钮
       if (isDeleteMode) {
           // 遍历每个现有的水平布局并添加删除按钮
           for(int i = 0; i < ui->widgetVLayout_fixed->count(); ++i) {
               // 获取水平布局
               QLayoutItem* item = ui->widgetVLayout_fixed->itemAt(i);
              QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());
               if (hLayout) {
                   // 创建一个新的删除按钮并将其添加到水平布局中
                   QPushButton *deleteButton = new QPushButton("删除");
                   connect(deleteButton, &QPushButton::clicked, this, &Widget_fixed::onDeleteButtonClicked);
                   deleteButton->setProperty("row", i);//给按钮设置属性，属性名称为row，属性值为i

                   hLayout->addWidget(deleteButton);
               }
           }
           // 禁用添加按钮
                  ui->addButton->setDisabled(true);
       } else {
           // 如果不在删除模式，就将所有删除按钮从布局中移除
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
               // 启用添加按钮
                       ui->addButton->setEnabled(true);
           }

      }
}
void Widget_fixed::onDeleteButtonClicked(){
    // 获取发送信号的按钮
       QPushButton *button = qobject_cast<QPushButton*>(sender());
       if (button) {
           // 从按钮的属性中获取行号
           int row = button->property("row").toInt();




           //水平布局数量大于一时
           if (ui->widgetVLayout_fixed->count() > 1) {
           //删除相应水平布局
           // 获取对应的水平布局（使用ui->widgetVLayout_fixed）
           QLayoutItem* item = ui->widgetVLayout_fixed->itemAt(row);
           QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());

           // 如果找到布局，则使用 delete 操作符将其删除
           if (hLayout) {
               // 遍历并删除子控件
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

               // 使用 removeItem 方法将水平布局从垂直布局中删除
               ui->widgetVLayout_fixed->removeItem(item);

               // 使用 delete 操作符将水平布局删除
               delete hLayout;
           }
               // 从数据库中删除相应的数据

           QSqlQuery query;
           QString sql = QString("DELETE FROM item WHERE rowid IN (SELECT rowid FROM item LIMIT 1 OFFSET %1)") .arg(row - 1);
           query.exec(sql);
       }
       }
       //水平布局数量等于一
       else if(ui->widgetVLayout_fixed->count() == 1){
           QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(ui->widgetVLayout_fixed->itemAt(0)->layout());
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
                       delete hLayout;
                       ui->widgetVLayout_fixed->removeItem(ui->widgetVLayout_fixed->itemAt(0));
                       QSqlQuery query;
                       query.exec("DELETE FROM item");

       }
}
