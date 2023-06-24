#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    int achievement_state; //成就状态 n表示达到第n个成就，初始为0

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
