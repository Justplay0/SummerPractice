#include "widget_fixed.h"
#include"head_fixed.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget_fixed w;
    w.setWindowTitle("添加待办事项");
    w.show();
    return a.exec();
}
