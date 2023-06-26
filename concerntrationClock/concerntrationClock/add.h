#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include<QPushButton>
#include<QSqlQuery>

namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    //void sendsignal();//向主界面发送通知关闭的消息
    //void getThingStr(QString &str);
    //void getTimeStr(QString &str);
    void getStr();
private:
    Ui::Add *ui;

};

#endif // ADD_H
