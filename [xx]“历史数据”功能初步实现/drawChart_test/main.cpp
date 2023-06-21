#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    int count = 5;

    QString showString = "您已经获得了" + QString::number(count) + "个番茄 " + "工作了" + QString::number(count) +"分钟";

    QApplication a(argc, argv);
    Dialog w;
    w.setWindowTitle(showString);
    w.show();

    return a.exec();
}
