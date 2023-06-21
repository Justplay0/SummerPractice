#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget1; }
QT_END_NAMESPACE

class Widget1 : public QWidget
{
    Q_OBJECT

public:
    Widget1(QWidget *parent = nullptr);
    ~Widget1();

private slots:
    void on_addButton_clicked();
    void onNameEntered();
private:
    Ui::Widget1 *ui;

};
#endif // WIDGET1_H
