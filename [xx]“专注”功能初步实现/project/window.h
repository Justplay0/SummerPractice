#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include <QLabel>
#include <QTimer>
#include <QPushButton>

class Window : public QWidget {
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    inline void onClockTime();
    inline void startClock();

    inline void Addtime();
    inline void Subtime();
    ~Window();
private:
    QPushButton AddMin,SubMin;
    QPushButton Start;

    QLabel timedisplayer, timeoutdisplayer, tip1;
    QTimer timer;

    int time, timeout, timeout2;
    bool StartOrNot, sate;
};
#endif // WINDOW_H
