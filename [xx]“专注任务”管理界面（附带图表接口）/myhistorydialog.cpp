#include "myhistorydialog.h"
#include "ui_myhistorydialog.h"
#include "myHistoryDialog.h"

myHistoryDialog::myHistoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myHistoryDialog)
{
    //空参咱就不考虑的，基本啥都没写
    ui->setupUi(this);

    m_pH = new CHistogram(this);
}

//自己写的构造函数实现：
myHistoryDialog::myHistoryDialog(int maximumUpCount,QVector<QString> taskNameVector,QVector<int> taskCountVector,int nullCount,QWidget *parent):
    QDialog(parent),
    ui(new Ui::myHistoryDialog)
{
    ui->setupUi(this);

    m_pH = new CHistogram(maximumUpCount,taskNameVector,taskCountVector,nullCount,this);

    //在historydialog建立的时候 就 给m_pH赋值上标的情况，
    m_pH->refreshUI(taskCountVector);
}

myHistoryDialog::~myHistoryDialog()
{
    delete ui;
}
