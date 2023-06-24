#include "adddialog.h"
#include "ui_adddialog.h"

#include"head_fixed.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);


}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::on_commitButton_fixed_clicked()
{
    //两个编辑框置零
    ui->fixednameEdit->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    //读取lineEdit和timeEdit
    QString name=ui->fixednameEdit->text();
    QDateTime dateTime = ui->dateTimeEdit->dateTime();
    QString datetimeStr=dateTime.toString();


    QString sql1=QString("CREATE TABLE item (name TEXT,time TEXT)");//创建表单item
    QString sql2=QString("INSERT INTO item (name, time) VALUES ('%1', '%2')").arg(name).arg(datetimeStr);//插入数据name和datetimeStr
    QSqlQuery query;//创建数据库
    if (!query.exec(sql1)) {
        qDebug() << "Failed to create table!";
    }
    if (!query.exec(sql2)) {
        qDebug() << "Failed to insert data!";
    }
    emit nameEntered();
    //关闭当前窗口
    this->hide();

}
