#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include<QMessageBox>
#include<QString>
namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = nullptr);
    ~addDialog();
signals:
    void nameEntered();
private slots:
    void on_commitButton_fixed_clicked();

private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
