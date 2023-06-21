#ifndef FBALLWIDGET_H
#define FBALLWIDGET_H

#include <QWidget>

class FBallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FBallWidget(QWidget *parent = 0);

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
};

#endif // FBALLWIDGET_H
