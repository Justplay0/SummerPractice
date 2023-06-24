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
    QPixmap pixmap("\\add.jpg");
    QPixmap pix = pixmap.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);//平滑算法，设置了图片规格
    ui->addButton->setIcon(QIcon(pix));//粘贴图片
    //Qt::FastTransformation：快速算法，可能会导致图片质量较差。
   //Qt::SmoothTransformation：平滑算法，可以获得更好的图片质量，但速度较慢。

    //打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("myDb.sqlite");
    if (!db.open()) {
        qDebug() << "Failed to connect to database!";
    } else {
        qDebug() << "Connected to database!";
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
    connect(dialog,&addDialog::nameEntered,this,&Widget_fixed::onNameEntered);
    dialog->show();
}
void Widget_fixed::onNameEntered()
{
     QString name;
     QString datetime;
    QSqlQuery query;
    if (query.exec("SELECT * FROM item")) {
        while (query.next()) {
            name= query.value(0).toString();
            datetime = query.value(1).toString();
        }
    } else {
        qDebug() << "Failed to query data!";
    }
    //两个标签，用来显示name和time

    auto *HLayout=new QHBoxLayout;

    auto *label = new QLabel(name+" "+datetime, this);

    HLayout->addWidget(label);

    //把新的水平布局添加到ui上的垂直布局
    ui->widgetVLayout_fixed->addLayout(HLayout);

}
