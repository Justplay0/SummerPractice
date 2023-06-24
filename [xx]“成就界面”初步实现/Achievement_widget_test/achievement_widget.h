#ifndef ACHIEVEMENT_WIDGET_H
#define ACHIEVEMENT_WIDGET_H

#include <QWidget>

namespace Ui {
class Achievement_Widget;
}

class Achievement_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Achievement_Widget(QWidget *parent = nullptr);
    ~Achievement_Widget();

private:
    Ui::Achievement_Widget *ui;
};

#endif // ACHIEVEMENT_WIDGET_H
