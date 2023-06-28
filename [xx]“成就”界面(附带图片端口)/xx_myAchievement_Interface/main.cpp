#include "myachievementwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myAchievementWidget w;
    w.show();

    return a.exec();
}
