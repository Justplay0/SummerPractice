#include "widget1.h"
#include"adddialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("myDb.sqlite");
    if (!db.open()) {
        qDebug() << "Failed to connect to database!";
    } else {
        qDebug() << "Connected to database!";
    }
    Widget1 w;
    w.show();
    return a.exec();
}
