#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent) ,time(0), StartOrNot(false), timeout(25 * 60), sate(true) {
    this -> setWindowTitle("番茄时钟 0.1");                           //窗口标题
    this -> setFixedSize(200, 200);                                 //主要窗口的大小
    this -> setWindowFlag(Qt::WindowStaysOnTopHint);                //使此窗口位于其他窗口之上
    this -> setStyleSheet("background-color: rgb(255,255,255);");   //背景色白色

    //Start 为QPushButton
    Start.setParent(this);  //子窗口
    Start.move(70, 130);    //移动到70,130位置
    Start.resize(60 ,30);   //重新设置大小 60,30
    Start.setText("开始");   //按钮上的文本为“开始”

    //CSS，Start设计样式
    Start.setStyleSheet("QPushButton {"
                        "   background-color: rgb(82,181,254);"
                        "   font-family:\"Microsoft YaHei\";"
                        "   font: bold;"
                        "   color: rgb(255,255,255);"
                        "   border-style: solid;"
                        "   border-radius: 5px;"
                        "}"

   //hover为状态，悬停在上面的时候背景色变淡蓝色

                        "QPushButton:hover {"
                        "   background-color:rgb(101,200,255);"
                        "}");

    //AddMin 为QPushButton
    AddMin.setParent(this); //子窗口
    AddMin.setText("+");    //设置文本，显示一个“+”符号
    AddMin.move(50, 40);    //移动位置
    AddMin.resize(20, 20);  //大小

    //CSS，QPushButton设计样式
    AddMin.setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"Microsoft YaHei\";"
                         "  font: bold;"
                         "  color: rgb(82,181,254);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"

    //pressed伪状态，按下的时候变成“深蓝色”

                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    //SubMin 为QPushButton
    SubMin.setParent(this); //子窗口
    SubMin.setText("-");    //设置文本，为一个“-”号
    SubMin.move(130, 40);   //移动位置
    SubMin.resize(20, 20);  //重新设置大小

    //CSS，设计样式

    SubMin.setStyleSheet("QPushButton {"
                         "  background-color: rgb(255,255,255);"
                         "  font-family: \"Microsoft YaHei\";"
                         "  font: bold;"
                         "  color: rgb(82,181,254);"
                         "  border-style: solid;"
                         "  border-radius: 2px;"
                         "  border-width: 1px;"
                         "}"

    //pressed伪状态，按下的时候变成“深蓝色”

                         "QPushButton:pressed {"
                         "  background-color: rgb(101,200,255);"
                         "  border-color: rgb(255,255,255);"
                         "  color: rgb(255,255,255);"
                         "}");

    //QLabel timedisplayer  最开始的中间那行字（0:0）
    timedisplayer.setParent(this);  //子窗口
    timedisplayer.move(57, 75);     //移动位置
    timedisplayer.resize(85, 35);   //大小

    //CSS设计label样式
    timedisplayer.setStyleSheet("QLabel {"
                                "   color:rgb(82,181,254);"
                                "   font-family:\"Microsoft YaHei\";"
                                "   font: bold 20px;"
                                "   font-size: 30px"
                                "}");

    timedisplayer.setText("0:0");   //设置显示的文本
    timedisplayer.setAlignment(Qt::AlignHCenter);   //居中

    //QLabel timeoutdisplayer
    timeoutdisplayer.setParent(this);
    timeoutdisplayer.move(90, 40);
    timeoutdisplayer.resize(20, 20);
    timeoutdisplayer.setStyleSheet("QLabel {"
                                   "   color:rgb(82,181,254);"
                                   "   font-family:\"Microsoft YaHei\";"
                                   "   font: bold 20px;"
                                   "   font-size: 15px"
                                   "}");

    //就是设置工作时间的中间的数  （+ 90 -）
    //timeout为总的定时时间，用秒（s）计算
    timeoutdisplayer.setText(QString::number(timeout/60, 10));
    timeoutdisplayer.setAlignment(Qt::AlignHCenter);

    //QLabel tip1   就是上面那行工作时间

    tip1.setParent(this);   //
    tip1.move(70, 10);      //移动位置
    tip1.resize(60, 20);    //大小

    //CSS设计
    tip1.setStyleSheet("QLabel {"
                       "   color:rgb(82,181,254);"
                       "   font-family:\"Microsoft YaHei\";"
                       "   font-size: 15px"
                       "}");

    tip1.setText("工作时间");   //文本
    tip1.setAlignment(Qt::AlignHCenter);    //居中



    //timer联系onClockTime函数
    connect(&timer, &QTimer::timeout, this, &Window::onClockTime);
    //Start （开始按钮） 联系startClock函数
    connect(&Start, &QPushButton::released, this, &Window::startClock);
    //AddMin （+号）   联系AddTime函数
    connect(&AddMin, &QPushButton::released, this, &Window::Addtime);
    //SubMin （-号）   联系SubTime函数
    connect(&SubMin, &QPushButton::released, this, &Window::Subtime);
}

Window::~Window() {
    timer.stop();
}

//与timer联系
inline void Window::onClockTime() {
    //还没到时间，且sate==true，即工作状态
    if((time < timeout)&&sate == true) {
        //显示工作时间，并且time++
        timedisplayer.setText(QString::number(time/60, 10)+":"+QString::number(time%60, 10));
        time++;
    }
    //如果已经到了时间，且处于工作状态
    else
    {
        if(sate == true) {  //排除法
            //sate取反
            time = sate = 0;
            timeout2 = timeout;
            timeout = 10 * 60;  //定时休息10min
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

//与开始按钮联系
inline void Window::startClock() {
    //不显示tiemout定时
    timeoutdisplayer.hide();

    //tip1换位置，“工作时间”变为“工作中”
    tip1.move(68, 30);
    tip1.resize(65, 30);
    tip1.setStyleSheet("QLabel {"
                       "   color:rgb(82,181,254);"
                       "   font-family:\"Microsoft YaHei\";"
                       "   font: bold 10px;"
                       "   font-size: 20px"
                       "}");
    tip1.setText("工作中");

    //隐藏+ -
    AddMin.hide();
    SubMin.hide();

    //startornot = true 为停止， = false 为开始
    //开始
    if(StartOrNot != true) {

        timer.start(1000);
        //切换显示
        Start.setText("停止");
        StartOrNot = !StartOrNot;
    }
    //结束
    else
    {
        //不计数了
        timer.stop();
        //切换显示
        Start.setText("开始");
        StartOrNot = !StartOrNot;
    }
}

//+ 按钮
inline void Window::Addtime() {
    //按一下，+60s，显示
    timeout += 60;
    timeoutdisplayer.setText(QString::number(timeout/60, 10));
}

//- 按钮
inline void Window::Subtime() {
    //最少60s，即一分钟
    if(timeout>60){
        timeout -=60;
    }else{
        timeout = 60;
    }
    timeoutdisplayer.setText(QString::number(timeout/60, 10));
}
