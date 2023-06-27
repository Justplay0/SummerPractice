#ifndef WIDGET_FIXED_H
#define WIDGET_FIXED_H

#include <QWidget>
#include<QCheckBox>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget_fixed; }
QT_END_NAMESPACE

class Widget_fixed : public QWidget
{
    Q_OBJECT

public:
    Widget_fixed(QWidget *parent = nullptr);
    ~Widget_fixed();
    bool isDeleteMode=false;
    void loadItems();
    void setTimer();


    int rowCount = -1;
    struct TimeEvent {
        QTimer* timer;
        QString eventName;
    };
public slots:
    void messageTimeout();
private slots:
    void on_addButton_clicked();
    void on_manageButton_clicked();
    void onDeleteButtonClicked();
    void onchooseButtonClicked();
    void clearData();
    void clearTimer();
private:
    Ui::Widget_fixed *ui;
    QList<QTimer*> messageTimers; // 声明一个 QTimer 对象指针的列表

    QList<TimeEvent> timerEvents; // 用于管理定时器和事件名称组合的列表
};
#endif // WIDGET_FIXED_H
