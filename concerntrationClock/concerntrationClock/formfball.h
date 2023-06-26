#ifndef FBALLWIDGET_H
#define FBALLWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QString>
class FBallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FBallWidget(QWidget *parent = 0);
    inline void onClockTime();
    ~FBallWidget();
    void updateTimeDisplay();

protected:
    void mousePressEvent(QMouseEvent *event);//鼠标按下事件处理
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件处理
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件处理
    void mouseDoubleClickEvent(QMouseEvent * event);//鼠标双击事件处理
    void enterEvent(QEvent *event);//鼠标进入事件处理
    void leaveEvent(QEvent *event);//鼠标离开事件处理
    void contextMenuEvent(QContextMenuEvent * e);//右键菜单事件处理
    void paintEvent(QPaintEvent *event);
signals:
    void notifyExitSoftSig();//悬浮窗关闭时的信号

public slots:
    void setContent(const QString &content);//用于接收要显示的内容
    void OnBallHideSlot();//自动隐藏悬浮窗
    void OnCloseSlot();//关闭悬浮窗窗口
    void OnCountSlot();


private:
    QPoint m_point;//鼠标当前位置
    QPixmap m_bg;//小球界面背景图
    bool m_press;//鼠标是否按下
    bool m_over;//鼠标是否在悬浮球上
    bool isHide;//小球是否隐藏
    QTimer* m_timer;//表示计时器，用于控制小球的移动
    QPushButton AddMin,SubMin;
    QPushButton Start;

    QLabel timedisplayer, timeoutdisplayer, tip1;
    QTimer timer;

    int time, timeout, timeout2;
    bool StartOrNot, sate;

private:
    QLabel *m_label;
};





#endif // FBALLWIDGET_H

