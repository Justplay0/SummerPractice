#ifndef ADDNEW_WIDGET_H
#define ADDNEW_WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QSpinBox>
#include <QAbstractSpinBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>

namespace Ui {
class AddNew_Widget;
}

class AddNew_Widget : public QWidget
{
    Q_OBJECT

signals:
    //信号，提醒专注页面需要update
    void AddNewAskUpdate();

public:
    explicit AddNew_Widget(QWidget *parent = nullptr);
    ~AddNew_Widget();

    //输入任务名 变量
    QString inputTaskeName;
    //输入任务时间 变量
    //如果无任何操作，那么时间就无法确定，那么就默认最初始的30
    int inputConcentrationTime = 30;

    //获取输入任务名 函数
    void AddNew_getInputTaskName();
    //获取输入任务时间 函数
    void AddNew_getInputConcentrationTime();
    //刷新主页面
    void AddNew_updateMainWidget();

private:
    Ui::AddNew_Widget *ui;
};

#endif // ADDNEW_WIDGET_H
