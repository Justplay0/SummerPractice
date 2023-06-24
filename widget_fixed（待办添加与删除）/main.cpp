#include "widget_fixed.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget_fixed w;
    w.show();
    return a.exec();
}
