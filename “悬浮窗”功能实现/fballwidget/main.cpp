#include "widget.h"
#include <QApplication>
#include "fballwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    Widget w;
    //    w.show();
    FBallWidget w;
    w.show();

    return a.exec();
}
