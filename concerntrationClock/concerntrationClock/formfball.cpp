#include "formfball.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QMenu>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include<QPainterPath>
#include <QAction>
#include <QContextMenuEvent>
#include <QVBoxLayout>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


FBallWidget::FBallWidget(QWidget *parent)
    : QWidget(parent)

{
    tip1.setParent(this);   //
    tip1.move(70, 25);      //移动位置
    tip1.resize(150, 80);    //大小

    //CSS设计
    tip1.setStyleSheet("QLabel {"
                       "   color:rgb(110,110,110);"
                       "   font-family:\"Microsoft YaHei\";"
                       "   font-size: 20px"
                       "}");

    tip1.setText("工作时间");   //文本
        tip1.setAlignment(Qt::AlignHCenter);    //居中

    //QLabel timedisplayer  最开始的中间那行字（00:00）
    timedisplayer.setParent(this);  //子窗口
    timedisplayer.move(70, 75);     //移动位置
    timedisplayer.resize(150, 35);   //大小

    //CSS设计label样式
    timedisplayer.setStyleSheet("QLabel {"
                                "   color:rgb(82,181,254);"
                                "   font-family:\"Microsoft YaHei\";"
                                "   font: bold 20px;"
                                "   font-size: 30px"
                                "}");

    timedisplayer.setText("00:00");   //设置显示的文本
    timedisplayer.setAlignment(Qt::AlignHCenter);   //居中


    // 连接数据库并查询用户设置的时间参数
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("myDb.sqlite");
//    if (db.open()) {
//        QSqlQuery query("SELECT time_param FROM user_settings;");
//        if (query.next()) {
//            int timeout = query.value(0).toInt(); // 获取用户设置的时间参数
//            // 使用 QTimer 定义一个定时器，并设置时间间隔为 time_param 秒
//            QTimer *timer = new QTimer(this);
//            timer->setInterval(timeout * 1000);
//            // 使用定时器的 timeout() 信号连接一个槽函数来更新窗口上的显示
//            connect(timer, SIGNAL(timeout()), this, SLOT(updateTimeDisplay()));
//            timer->start(); // 启动定时器
//        }
//    }


    m_label = new QLabel(this);


    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);//设置窗口，无边框，置顶and工具窗口
    setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明

    m_press = false;//初始化鼠标未置于小球上
    this->setFixedSize(360, 200);//设置窗口大小

    int screenWidth = QApplication::desktop()->screenGeometry().width();//获取屏幕宽度
    int screenHeight = QApplication::desktop()->screenGeometry().height();//获取屏幕高度
    this->move(screenWidth /2-150, screenHeight /2-30);//放置悬浮窗至右下角

    connect(this, SIGNAL(notifyExitSoftSig()), this, SLOT(OnCloseSlot()));//连接，用于响应关闭窗口的事件

    //动画，延迟关闭窗口，否则会有抖动
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnBallHideSlot()));
    //连接超时信号timeout()与槽函数OnBallHideSlot()，实现悬浮窗关闭

}

FBallWidget::~FBallWidget() {
    timer.stop();
}

void FBallWidget::updateTimeDisplay(){
    //还没到时间，且sate==true，即工作状态
    if((time < timeout)&&sate == true) {
        //显示工作时间，并且time++
        int hour = QString::number(time/3600, 10).toInt();
        int minute = QString::number((time%3600)/60, 10).toInt();
        int second = QString::number(time%60, 10).toInt();
        if(time/3600)
            timedisplayer.setText(QString("%1").arg(hour, 2, 10, QChar('0'))+":"+QString("%1").arg(minute, 2, 10, QChar('0'))+":"+QString("%1").arg(second, 2, 10, QChar('0')));
        else
            timedisplayer.setText(QString("%1").arg(minute, 2, 10, QChar('0'))+":"+QString("%1").arg(second, 2, 10, QChar('0')));
        time++;
    }
    //如果已经到了时间，且处于工作状态
    else
    {
        if(sate == true) {  //排除法
            //sate取反
            time = sate = 0;
            timeout2 = timeout;
            timeout = 5 * 60;  //定时休息5min
            tip1.setText("休息中");
        }
    }

    //时间未到，且sate==false,即休息状态
    if((time < timeout)&&sate == false) {
        //显示时间，并且time++
        timedisplayer.setText(QString::number(time/60, 10)+":"+QString::number(time%60, 10));
        time++;
    }else {
        //时间到了，sate ==false 还在休息状态
        if(sate == false) {
            //time清零
            time = 0;
            //转换为工作状态
            sate = 1;
            //继承原来timeout
            timeout = timeout2;
            tip1.setText("工作中");
        }
    }
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
/*处理鼠标释放事件。当用鼠标左键释放小球时，
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

void FBallWidget::contextMenuEvent(QContextMenuEvent * e) //重写鼠标按下事件
{
    QMenu menu;
    menu.addAction(QStringLiteral("exit"));

    QAction *act = menu.exec(QCursor::pos());

    if(act && act->text() == QStringLiteral("exit"))
    {
// 创建新窗口
        QWidget *exitWindow = new QWidget(this);
        exitWindow->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

        exitWindow->setWindowModality(Qt::ApplicationModal); //设置为应用程序模态
        exitWindow->setFixedSize(300, 100); //设置窗口大小
        QVBoxLayout *layout = new QVBoxLayout(exitWindow); //设置布局
        QLabel *label = new QLabel("是否放弃本次专注？", exitWindow);
        layout->addWidget(label);
        QHBoxLayout *buttonLayout = new QHBoxLayout; //创建水平布局
        QPushButton *confirmBtn = new QPushButton("确定", exitWindow);
        QPushButton *cancelBtn = new QPushButton("取消", exitWindow);
        buttonLayout->addWidget(confirmBtn);
        buttonLayout->addWidget(cancelBtn);
        layout->addLayout(buttonLayout);

// 点击确定按钮返回新界面
        connect(confirmBtn, &QPushButton::clicked, [=]{
            qDebug() << "跳转至下一个窗口";
            QWidget *nextWindowToConnect = new QWidget();//连接番茄事项窗口
            nextWindowToConnect->show();
            exitWindow->close();
            close();//关闭当前窗口
        });

        // 点击取消按钮返回原界面
        connect(cancelBtn, &QPushButton::clicked, [=]{
            exitWindow->close(); //关闭新窗口，返回原窗口
        });

        exitWindow->show();
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
    QPoint thisPos = this->pos();
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

void FBallWidget::paintEvent(QPaintEvent *e)//实现悬浮球界面的绘制
{
    QPainter painter(this);
    QPainterPath pathFill;
    pathFill.setFillRule(Qt::WindingFill);
    int startX = 0;
    int startY = 0;
    QPainterPath pathFill1;
    QRectF rect(startX, startY, 358, 215);
    QImage image(":/new/prefix2/fball.png"); // 加载图片
    image = image.scaled(rect.size().toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation); // 缩放图片使其刚好填满矩形
    QBrush brush(image); // 将图片设置为纹理
    painter.fillRect(rect, brush); // 使用纹理填充矩形
}


void FBallWidget::setContent(const QString &content)
{
    m_label->setText(content);
}



void FBallWidget::onClockTime() {

}


