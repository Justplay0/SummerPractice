#ifndef MYCONCENTRATIONMAINWINDOW_H
#define MYCONCENTRATIONMAINWINDOW_H

#include "addnew_widget.h"
#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QMessageBox>
#include <QLabel>
#include <QObject>

namespace Ui {
class MyConcentrationMainWindow;
}

class MyConcentrationMainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void Heard_updateMainWindow();

public:
    explicit MyConcentrationMainWindow(QWidget *parent = nullptr);
    ~MyConcentrationMainWindow();

    //点击“添加”后创建widget界面，函数声明
    void triggered_CreateNewWidget();

    //“刷新数据库表单”函数，重新分配uid，函数声明
    void updateDatabase();

private:
    Ui::MyConcentrationMainWindow *ui;
};

#endif // MYCONCENTRATIONMAINWINDOW_H
