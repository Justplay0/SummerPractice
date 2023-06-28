#ifndef MYACHIEVEMENTWIDGET_H
#define MYACHIEVEMENTWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QObject>

namespace Ui {
class myAchievementWidget;
}

class myAchievementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myAchievementWidget(QWidget *parent = nullptr);
    ~myAchievementWidget();

private:
    Ui::myAchievementWidget *ui;
};

#endif // MYACHIEVEMENTWIDGET_H
