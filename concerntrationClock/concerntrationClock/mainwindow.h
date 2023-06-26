#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QHBoxLayout>
#include<QPushButton>
#include<QSqlDatabase>
#include<QDebug>
#include<QLayout>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setStr();
    void setNewStr();
    void onFindDelete();
    ~MainWindow();


private slots:
    void addMenuSlot();
    void deleteButtonClicked();
    void onStartButtonClicked();//+
private:
    Ui::MainWindow *ui;
    QGridLayout *gridLayout;
    QSqlDatabase database;
    int orow;
    int nrow;
};
#endif // MAINWINDOW_H
