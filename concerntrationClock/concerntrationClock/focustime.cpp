//#include "focustime.h"
//#include"fballwidget.h"

//Window::Window(QWidget *parent)
//    : QWidget(parent) ,time(0), StartOrNot(false), timeout(30 * 60), sate(true) {

//    //CSS设计label样式
//    timedisplayer.setStyleSheet("QLabel {"
//                                "   color:rgb(82,181,254);"
//                                "   font-family:\"Microsoft YaHei\";"
//                                "   font: bold 20px;"
//                                "   font-size: 30px"
//                                "}");

//    timedisplayer.setText("00:00");   //设置显示的文本
//    timedisplayer.setAlignment(Qt::AlignHCenter);   //居中

//    //QLabel timeoutdisplayer
//    timeoutdisplayer.setParent(this);
//    timeoutdisplayer.move(90, 40);
//    timeoutdisplayer.resize(20, 20);
//    timeoutdisplayer.setStyleSheet("QLabel {"
//                                   "   color:rgb(82,181,254);"
//                                   "   font-family:\"Microsoft YaHei\";"
//                                   "   font: bold 20px;"
//                                   "   font-size: 15px"
//                                   "}");

//    //就是设置工作时间的中间的数  （+ 90 -）
//    //timeout为总的定时时间，用秒（s）计算
//    timeoutdisplayer.setText(QString::number(timeout/60, 10));
//    timeoutdisplayer.setAlignment(Qt::AlignHCenter);

//    //QLabel tip1   就是上面那行工作时间

//    tip1.setParent(this);   //
//    tip1.move(70, 10);      //移动位置
//    tip1.resize(60, 20);    //大小

//    //CSS设计
//    tip1.setStyleSheet("QLabel {"
//                       "   color:rgb(82,181,254);"
//                       "   font-family:\"Microsoft YaHei\";"
//                       "   font-size: 15px"
//                       "}");

//    tip1.setText("工作时间");   //文本
//        tip1.setAlignment(Qt::AlignHCenter);    //居中

//    //timer联系onClockTime函数
//    connect(&timer, &QTimer::timeout, this, &Window::onClockTime);

//}

//Window::~Window() {
//    timer.stop();
//}
////与timer联系
//inline void Window::onClockTime() {
//    //还没到时间，且sate==true，即工作状态
//    if((time < timeout)&&sate == true) {
//        //显示工作时间，并且time++
//        int hour = QString::number(time/3600, 10).toInt();
//        int minute = QString::number((time%3600)/60, 10).toInt();
//        int second = QString::number(time%60, 10).toInt();
//        if(time/3600)
//            timedisplayer.setText(QString("%1").arg(hour, 2, 10, QChar('0'))+":"+QString("%1").arg(minute, 2, 10, QChar('0'))+":"+QString("%1").arg(second, 2, 10, QChar('0')));
//        else
//            timedisplayer.setText(QString("%1").arg(minute, 2, 10, QChar('0'))+":"+QString("%1").arg(second, 2, 10, QChar('0')));
//        time++;
//    }
//    //如果已经到了时间，且处于工作状态
//    else
//    {
//        if(sate == true) {  //排除法
//            //sate取反
//            time = sate = 0;
//            timeout2 = timeout;
//            timeout = 5 * 60;  //定时休息5min
//            tip1.setText("休息中");
//        }
//    }

//    //时间未到，且sate==false,即休息状态
//    if((time < timeout)&&sate == false) {
//        //显示时间，并且time++
//        timedisplayer.setText(QString::number(time/60, 10)+":"+QString::number(time%60, 10));
//        time++;
//    }else {
//        //时间到了，sate ==false 还在休息状态
//        if(sate == false) {
//            //time清零
//            time = 0;
//            //转换为工作状态
//            sate = 1;
//            //继承原来timeout
//            timeout = timeout2;
//            tip1.setText("工作中");
//        }
//    }
//}

////与开始按钮联系
////inline void Window::startClock() {

////    //不显示tiemout定时
////    timeoutdisplayer.hide();

////    //tip1换位置，“工作时间”变为“工作中”
////    tip1.move(68, 30);
////    tip1.resize(65, 30);
////    tip1.setStyleSheet("QLabel {"
////                       "   color:rgb(82,181,254);"
////                       "   font-family:\"Microsoft YaHei\";"
////                       "   font: bold 10px;"
////                       "   font-size: 20px"
////                       "}");
////    tip1.setText("工作中");

////    //隐藏+ -
////    AddMin.hide();
////    SubMin.hide();

////    //startornot = true 为停止， = false 为开始
////    //开始
////    if(StartOrNot != true) {

////        timer.start(1000);
////        //切换显示
////        Start.setText("停止");
////        StartOrNot = !StartOrNot;
////    }
////    //结束
////    else
////    {
////        //不计数了
////        timer.stop();
////        //切换显示
////        Start.setText("开始");
////        StartOrNot = !StartOrNot;
////    }
////}

//////+ 按钮
////inline void Window::Addtime() {
////    //按一下，+30min，显示
////    timeout += 1800;
////    timeoutdisplayer.setText(QString::number(timeout/60, 10));
////}

//////- 按钮
////inline void Window::Subtime() {
////    //最少30min
////    if(timeout>1800){
////        timeout -=1800;
////    }else{
////        timeout = 1800;
////    }
////    timeoutdisplayer.setText(QString::number(timeout/60, 10));
////}
////void MainWindow::onStartButtonClicked()
////{
////    this->close();
////    FBallWidget *window = new FBallWidget(this);
////    window->show();
////}
