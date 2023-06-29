#ifndef MYACHIEVEMENTLABEL_H
#define MYACHIEVEMENTLABEL_H

#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QSequentialAnimationGroup>

class myAchievementLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myAchievementLabel(QWidget *parent = nullptr);

    explicit myAchievementLabel(QString labelImg);

    QString labelImgPath;

    void zoom1();
    void zoom2();

    //下坠bug暂时封禁
    //void enterEvent(QEvent *event);

signals:

public slots:
};

#endif // MYACHIEVEMENTLABEL_H


