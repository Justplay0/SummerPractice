#include "Dialog.h"
#include <QDate>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    m_pH = new CHistogram(this);

    this->startTimer(2000);
}

Dialog::~Dialog()
{

}

void Dialog::timerEvent(QTimerEvent *event)
{
    //bool bIsa 逐次取反，连续的跳跃
    static bool bIsa;
    bIsa = !bIsa;

    //vec1,vec2两个vector添加7个数据，表示 上标数据
    QVector<int> vec1;
    vec1<<1<<23<<3<<14<<12<<6<<7;

    QVector<int> vec2;
    vec2<<17<<6<<5<<18<<3<<12<<1;

    //refreshUI传入Qvector<int>，刷新 上标数据
    if(bIsa)
        m_pH->refreshUI(vec1);
    else
        m_pH->refreshUI(vec2);
}


