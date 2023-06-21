#include "widget1.h"
#include "ui_widget1.h"
#include"adddialog.h"
Widget1::Widget1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget1)
{
    ui->setupUi(this);
    //这个是addButton粘贴图片
    QPixmap pixmap("D:\\qt things\\try111\\add.jpg");
    QPixmap pix = pixmap.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);//平滑算法，设置了图片规格
    ui->addButton->setIcon(QIcon(pix));//粘贴图片
    //Qt::FastTransformation：快速算法，可能会导致图片质量较差。
   //Qt::SmoothTransformation：平滑算法，可以获得更好的图片质量，但速度较慢。
}

Widget1::~Widget1()
{
    delete ui;
}


void Widget1::on_addButton_clicked()
{
    //创建了对话框用来添加项目
    addDialog *dialog=new addDialog;
    dialog->setWindowTitle("添加项目");
    //接收对话框传来的点击确认的信号，然后调用onNameEntered
    connect(dialog,&addDialog::nameEntered,this,&Widget1::onNameEntered);
    dialog->show();
}
void Widget1::onNameEntered()
{
     QString name;
     QString time;
    QSqlQuery query;
    if (query.exec("SELECT * FROM item")) {
        while (query.next()) {
            name= query.value(0).toString();
            time = query.value(1).toString();
        }
    } else {
        qDebug() << "Failed to query data!";
    }
    //两个标签，用来显示name和time
    auto *HLayout=new QHBoxLayout;

    auto *label = new QLabel(name+" "+time, this);

    HLayout->addWidget(label);

    //把新的水平布局添加到ui上的垂直布局
    ui->widgetVLayout->addLayout(HLayout);
}
