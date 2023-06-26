#include "mainwindow.h"
#include "add.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
#include"formfball.h"
#include"QObject"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //这个是addButton粘贴图片
    //QPixmap pixmap("\\add.jpg");
    //QPixmap pix = pixmap.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);//平滑算法，设置了图片规格
    //ui->addButton->setIcon(QIcon(pix));//粘贴图片
    //Qt::FastTransformation：快速算法，可能会导致图片质量较差。
    //Qt::SmoothTransformation：平滑算法，可以获得更好的图片质量，但速度较慢。

    // 创建布局
    gridLayout = new QGridLayout(this);
    ui->verticalLayout->addLayout(gridLayout);

    //初始化索引
    orow=0;
    nrow=0;

    //打开数据库
    database = QSqlDatabase::addDatabase("QSQLITE");
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("myDb.sqlite");
    if (!database.open()) {
        qDebug() <<"Error opening database:" << database.lastError().text();
        return;
    } else {
        qDebug() << "Connected to database!";
    }

    //创建表单item
    QSqlQuery query1;
    QString sql1=QString("CREATE TABLE IF NOT EXISTS item (name TEXT, time TEXT)");
    if (!query1.exec(sql1)) {
        qDebug() << "Failed to execute query:" << query1.lastError().text();
    }

    //读取数据库的数据
    setStr();

    //添加新的数据
    connect(this->ui->addMenu,&QMenu::aboutToShow,this,&MainWindow::addMenuSlot);
    //onnect(gridLayout,&MainWindow::deleteButtonClicked,this,&MainWindow::deleteLayout);


}

MainWindow::~MainWindow()
{
    //关闭数据库链接
    database.close();
    delete ui;
}

void MainWindow::setStr()
{
    // 清空所有项目布局
    QLayoutItem *item;
    while ((item = this->gridLayout->takeAt(0))) {
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
    else
    {
        while (query.next()) {
            QString name = query.value("name").toString();
            QString time = query.value("time").toString();
            //在界面上显示读取的数据
            auto *HLayout=new QHBoxLayout;

            auto *button = new QPushButton(name+"  "+time+"min", this);
            auto *Start = new QPushButton("开始",this);
            connect(Start, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
            //auto *Delete = new QPushButton("删除",this);
            //Delete->setProperty("row",layoutId);

            //Delete->setParentLayout(HLayout);

            HLayout->addWidget(button,4);
            HLayout->addWidget(Start,1);
            //HLayout->addWidget(Delete,1);


            //把新的水平布局添加到ui上的垂直布局
            gridLayout->addLayout(HLayout,orow,0);
            orow++;
        }
        //添加删除按钮
        onFindDelete();
    }

}

void MainWindow::addMenuSlot()
{
    Add *add = new Add;//创建子页面
    add->setWindowTitle("添加事件");
    add->show();//显示子页面
    connect(add,&Add::getStr,this,&MainWindow::setNewStr);
}


void MainWindow::setNewStr()
{
    QString name;
    QString datetime;
    // 从数据库中读取项目并显示
    QSqlQuery query;
    if (!query.exec("SELECT * FROM item")) {
        QSqlError error = query.lastError();
        qDebug() << "Failed to query data: " << error.text();
    }
    int i=0;
    while (query.next()) {
        QString name = query.value("name").toString();
        QString datetime = query.value("time").toString();
        //在界面上显示读取的数据
        //两个标签，用来显示name和time
        auto *HLayout=new QHBoxLayout;
        auto *button = new QPushButton(name+"  "+datetime+"min", this);
        auto *Start = new QPushButton("开始",this);
        //Start->setProperty("row",i);
        //auto *Delete = neStarw QPushButton("删除",this);
        //Delete->setProperty("row",layoutId);
        //Delete->setParentLayout(HLayout);
        HLayout->addWidget(button,4);
        HLayout->addWidget(Start,1);
        //HLayout->addWidget(Delete,1);
        //i++;
        //把新的水平布局添加到ui上的垂直布局
        gridLayout->addLayout(HLayout,orow+(nrow++),0);

    //添加删除按钮
    onFindDelete();
    }
    //connect(Delete,&QPushButton::clicked,this,&MainWindow::deleteButtonClicked);
}

void MainWindow::onFindDelete()
{
    //遍历所有水平布局，插入删除按钮
    if(nrow==0)
    {
        for(int i=0;i<orow;i++)
        {
            QLayoutItem* item= this->gridLayout->itemAt(i);
            QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());
            if (hLayout) {
                // 创建一个新的删除按钮并将其添加到水平布局中
                QPushButton *deleteButton = new QPushButton("删除");
                connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteButtonClicked);
                deleteButton->setProperty("row", i);//给按钮设置属性，属性名称为row，属性值为i

                hLayout->addWidget(deleteButton);
            }
        }
    }
    else
    {
        QLayoutItem* item= this->gridLayout->itemAt(nrow+orow);
        QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(item->layout());
        if (hLayout) {
            // 创建一个新的删除按钮并将其添加到水平布局中
            QPushButton *deleteButton = new QPushButton("删除");
            connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteButtonClicked);
            deleteButton->setProperty("row", nrow+orow);//给按钮设置属性，属性名称为row，属性值为i

            hLayout->addWidget(deleteButton);
        }

    //auto *HLayout=this->gridLayout->itemAt(row);
    //int row=this->gridLayout->ShowEvent(delete)
    //QPushButton* deleteButton = HLayout->Delete;
    //connect(deleteButton, &QPushButton::clicked, this, &::MainWindow::deleteButtonClicked);
    }
}
void MainWindow::deleteButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(!button)
        return;

    // 获取按钮的行号
    int row1 = button->property("row").toInt();


    //水平布局数量大于一时
    if (this->gridLayout->count() > 1) {
        //删除相应水平布局
        // 获取对应的水平布局
        QLayoutItem* item = this->gridLayout->itemAt(row1);
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
            this->gridLayout->removeItem(item);

            // 使用 delete 操作符将水平布局删除
            delete hLayout;
        }
        // 从数据库中删除相应的数据

        QSqlQuery query;
        QString sql = QString("DELETE FROM item WHERE rowid IN (SELECT rowid FROM item LIMIT 1 OFFSET %1)") .arg(row1 - 1);
        query.exec(sql);
    }
    //水平布局数量等于一
    else if(this->gridLayout->count() == 1){
        QHBoxLayout* hLayout = dynamic_cast<QHBoxLayout*>(this->gridLayout->itemAt(0)->layout());
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
        this->gridLayout->removeItem(this->gridLayout->itemAt(0));
        QSqlQuery query;
        query.exec("DELETE FROM item");

    }

 }

void MainWindow::onStartButtonClicked()
{
    this->close();
    FBallWidget *window = new FBallWidget(this);
    window->show();
}
