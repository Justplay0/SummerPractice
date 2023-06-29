#include "myconcentrationmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyConcentrationMainWindow w;
    w.show();

    return a.exec();
}
