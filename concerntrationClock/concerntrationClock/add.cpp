#include "add.h"
#include "ui_add.h"
#include <QDebug>

Add::Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);//子窗口关闭即销毁
}

Add::~Add()
{
    delete ui;
}

void Add::on_buttonBox_accepted()
{
    //emit sendsignal();
    QString thingStr=ui->lineEdit->text();
    //emit getThingStr(thingStr);
    QString timeStr=ui->spinBox->text();
    //emit getTimeStr(timeStr);
    QString sql1=QString("CREATE TABLE item (name TEXT,time TEXT)");//创建表单item
    QString sql2=QString("INSERT INTO item (name, time) VALUES ('%1', '%2')").arg(thingStr).arg(timeStr);//插入数据name和datetimeStr
    QSqlQuery query;//创建数据库
    if (!query.exec(sql1)) {
        qDebug() << "Failed to create table!";
    }
    if (!query.exec(sql2)) {
        qDebug() << "Failed to insert data!";
    }
    emit getStr();
    //this->hide();
    this->close();
}


void Add::on_buttonBox_rejected()
{
    //emit sendsignal();
    this->close();
}

