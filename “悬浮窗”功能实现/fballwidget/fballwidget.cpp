#include "fballwidget.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QMenu>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include<QPainterPath>>
#include <QAction>
#include <QContextMenuEvent>
#include "widget.h"

FBallWidget::FBallWidget(QWidget *parent)
    : QWidget(parent)

{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);//设置窗口，无边框，置顶and工具窗口
    setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明

    m_press = false;//初始化鼠标未置于小球上
    this->setFixedSize(345, 200);//设置窗口大小

    int screenWidth = QApplication::desktop()->screenGeometry().width();//获取屏幕宽度
    int screenHeight = QApplication::desktop()->screenGeometry().height();//获取屏幕高度
    this->move(screenWidth - 60, screenHeight * 0.618);//放置悬浮窗至右下角

    connect(this, SIGNAL(notifyExitSoftSig()), this, SLOT(OnCloseSlot()));//连接，用于响应关闭窗口的事件

    //动画，延迟关闭窗口，否则会有抖动
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnBallHideSlot()));
    //连接超时信号timeout()与槽函数OnBallHideSlot()，实现悬浮窗关闭

}

void FBallWidget::mousePressEvent(QMouseEvent *event)
/*处理鼠标按下事件的函数。当用鼠标左键点击悬浮窗时，将 m_press 设为 true，表示小球被按下，
 * 然后，计算出当前鼠标相对于小球左上角的位置，以便在移动鼠标时正确移动小球。
 * 函数参数 event 是一个 QMouseEvent 类型的变量，它包含了关于这个事件的详细信息，例如鼠标按下的位置、鼠标按下的键等。*/
{
    if(event->button() == Qt::LeftButton)
    {
        m_press = true;

    }

    m_point = event->globalPos() - pos();
}

void FBallWidget::mouseReleaseEvent(QMouseEvent *)
/*这个函数是处理小球的鼠标释放事件的函数。当用鼠标左键释放小球时，
 * 将 m_press 设为 false，表示小球被释放了。
 * 此时，小球不再跟随鼠标移动。*/
{

    m_press = false;
}

void FBallWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_press)
    {
        int screenWidth = QApplication::desktop()->screenGeometry().width();//获取屏幕宽度
        QPoint move_pos = event->globalPos();
        QPoint tarPos = move_pos - m_point;//计算小球应该被移动到的目标位置，其中`m_point`保存的是小球上次被按下时鼠标相对于小球左上角的位置。

        if(tarPos.x() + this->width() > screenWidth)//判断小球是否超出屏幕边界
        {
            tarPos.setX(screenWidth - this->width());//将小球横坐标调整到屏幕边缘
        }
        move(tarPos);//移动小球至目标位置
    }
}

void FBallWidget::mouseDoubleClickEvent(QMouseEvent * event)//双击事件处理
{
}

void FBallWidget::enterEvent(QEvent *event)
{
    int screenWidth = QApplication::desktop()->screenGeometry().width();
    if(this->geometry().x() + this->width() > screenWidth)
    {
        QRect rect = this->geometry();
        rect.setX(screenWidth - this->width());//如果超出了，就生成一个新的矩形`rect`，将小球的横坐标调整到屏幕边缘

        QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "geometry");
        pAnimation->setStartValue(this->geometry());
        pAnimation->setEndValue(rect);
        pAnimation->setEasingCurve(QEasingCurve::Linear);//线性缓动函数
        pAnimation->start(QAbstractAnimation::DeleteWhenStopped);//执行动画，结束后自动删除动画对象
    }
    isHide = true;//小球处于隐藏状态
    m_over = true;//鼠标在小球上
    update();//重绘，更新状态
}

void FBallWidget::leaveEvent(QEvent *event)
{
    m_timer->start(500);//鼠标离开小球区域时，会启动定时器。
    //在定时器回调函数中，会判断鼠标是否停留在小球上，
    //如果没有，则隐藏小球。如果是，则不做处理，直到鼠标离开小球后再隐藏。
}

void FBallWidget::contextMenuEvent(QContextMenuEvent * e)//处理右键，弹出菜单
{
    QMenu menu;
    menu.addAction(QStringLiteral("exit"));

    QAction *act = menu.exec(QCursor::pos());

    if(act && act->text() == QStringLiteral("exit"))
    {
        qDebug() << "show new window";//跳转至下一个窗口，此处连接任务界面
        Widget *newWindow = new Widget();
        newWindow->show();
        close();//关闭悬浮窗
    }
}


void FBallWidget::OnCloseSlot()//关闭窗口
{
    qDebug() << "OnCloseSlot";
    close();
}


void FBallWidget::OnBallHideSlot()//鼠标移出小球后，让小球自动隐藏的函数
{
    //获取悬浮窗和鼠标的位置
    QPoint cursorPoint = cursor().pos();
    //qDebug() << "cursorPoint: " << cursorPoint;
    QPoint thisPos = this->pos();
    //qDebug() << "this point: " << thisPos << " " << thisPos + QPoint(this->width(),this->height());
    //计算偏移量，超出范围时触发悬浮窗隐藏
    QPoint offsetPoint = cursorPoint - thisPos - QPoint(this->width(),this->height());
    if(offsetPoint.x() <= -340 || offsetPoint.y() >= 0 || offsetPoint.y() <= -80)
    {
        qDebug() << "offsetPoint:" << offsetPoint;
    }
    else
    {
        return;
    }

    m_timer->stop();
    int screenWidth = QApplication::desktop()->screenGeometry().width();//获取屏幕宽度
    if(this->geometry().x() + this->width() > screenWidth - 2)
    {
        QRect rect = this->geometry();
        rect.setX(screenWidth - 60);
        //创建一个动画对象pAnimation
        QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "geometry");
        pAnimation->setStartValue(this->geometry());//设置起始位置
        pAnimation->setEndValue(rect);//设置结束位置
        pAnimation->setEasingCurve(QEasingCurve::Linear);//动画曲线的缓动类型
        pAnimation->start(QAbstractAnimation::DeleteWhenStopped);//开始动画并设置删除策略为停止后自动删除
        isHide = false;//表示小球已经隐藏
    }
    m_over = false;
    update();
}

void FBallWidget::paintEvent(QPaintEvent *e)//实现悬浮球界面的绘制（这里后期基本全部改掉，用贴图代替）
{
    QPainterPath pathFill;
    pathFill.setFillRule(Qt::WindingFill);
    int startX = 22;
    int startY = 1;
    pathFill.addRect(startX,startY, 300,160);//小球右侧矩形框底色填充
    QPainterPath pathFill1;
    pathFill1.addEllipse(240 + startX, 105 + startY, 90, 90);//右下角小球底色填充

    QPainter painter(this);
    painter.setPen(QPen(QColor(0,0,0)));

    QPainterPath pathLine;


    //绘制渐变的底色
    QLinearGradient linearGradient(0,startY,0,startY + 200);
    linearGradient.setColorAt(0.0,QColor(252,252,252));//渐变色（上方
    linearGradient.setColorAt(1.0,QColor(200,200,200));//渐变色（下方
    painter.fillPath(pathFill1, QBrush(linearGradient));
    painter.fillPath(pathFill, QBrush(linearGradient));
    QLinearGradient linearGradient1(startX,0,345 + startX,0);

    painter.setPen(QPen(QBrush(linearGradient1),5));//小球外圈

    painter.drawLine(startX,startY,300+startX,startY);


    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawEllipse(240 + startX, 105 + startY, 90, 90);//右下角小球外圈
    painter.drawPixmap(3 + startX , 3 + startY, m_bg);//底色


    QPen pen(Qt::black);
    QFont font;
    font.setPointSize(6);
    pen.setWidthF(0.5);
    painter.setPen(pen);
    painter.setFont(font);


    font.setPointSize(10);
    pen.setWidthF(6);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setFont(font);

}


