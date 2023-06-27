#include "adddialog.h"
#include "ui_adddialog.h"
#include"widget_fixed.h"
#include"head_fixed.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);

    //编辑框置零
    ui->fixednameEdit->clear();
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss AP");
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::on_commitButton_fixed_clicked()
{


    //读取lineEdit和timeEdit
    QString name=ui->fixednameEdit->text();
    QDateTime dateTime = ui->dateTimeEdit->dateTime();
    QString datetimeStr=dateTime.toString();
    if(ui->message_fixed->isChecked()){
        isTime=true;
    }


    //插入数据

    QSqlQuery query;

    query.prepare("INSERT INTO item_fixed1(name, time, timer, checked) VALUES (:name, :time, :timer, :checked)");
    query.bindValue(":name", name);  // 替换为要插入的名称
    query.bindValue(":time", datetimeStr);  // 替换为要插入的时间
    query.bindValue(":timer", isTime?"true":"false");  // 替换为要插入的 timer 值
    query.bindValue(":checked", "false");  // 替换为要插入的 checked 值
    query.exec();



    emit nameEntered();
    //关闭当前窗口
    this->hide();


}
