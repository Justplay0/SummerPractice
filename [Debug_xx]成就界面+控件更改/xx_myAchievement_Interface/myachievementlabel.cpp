#include "myachievementlabel.h"

myAchievementLabel::myAchievementLabel(QWidget *parent) : QLabel(parent)
{

}

myAchievementLabel::myAchievementLabel(QString labelImg)
{
    labelImgPath = labelImg;

    QPixmap pixmap;
    bool ret = pixmap.load(labelImg);
    if(!ret)
    {
        qDebug()<<labelImg<<"加载图片失败!";
    }
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setPixmap(pixmap);
    //QPixmap scaledPixmap = pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio);
}

void myAchievementLabel::zoom1()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->pos().x(),this->pos().y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->pos().x(),this->pos().y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start();
}

void myAchievementLabel::zoom2()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->pos().x(),this->pos().y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->pos().x(),this->pos().y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start();
}

//有下坠bug，暂时封住
//void myAchievementLabel::enterEvent(QEvent *event)
//{
//    zoom1();
//    zoom2();
//}


