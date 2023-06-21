#include "adddialog.h"
#include "ui_adddialog.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QDebug>
#include<QString>
addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);

    // 在构造函数中建立信号和槽的连接，并使用QMetaObject::Connection保存连接
        auto connection = connect(ui->yesButton, &QPushButton::clicked, this, &addDialog::on_yesButton_clicked);
        // 在addDialog的析构函数中断开信号和槽的连接
        connect(this, &addDialog::destroyed, [connection]() {
            QObject::disconnect(connection);
        });

}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::on_yesButton_clicked()
{
    //读取lineEdit和timeEdit
    QString name=ui->nameEdit->text().trimmed();
    QTime time1 = ui->timeEdit->time();//把timeEdit的值赋值给time
    QString timeStr = time1.toString("hh:mm:ss");
    if (name.isEmpty()) {
           QMessageBox::warning(this, "警告", "请输入姓名", QMessageBox::Ok);
           return;
       }
    if (timeStr.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入时间", QMessageBox::Ok);
        return;
    }
    QString sql1=QString("CREATE TABLE item (name TEXT,time TEXT)");//创建表单item
    QString sql2=QString("INSERT INTO item (name, time) VALUES ('%1', '%2')").arg(name).arg(timeStr);//插入数据name和timeStr
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
    //两个编辑框置零
    ui->nameEdit->clear();
    ui->timeEdit->clear();

    }

