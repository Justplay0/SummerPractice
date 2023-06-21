#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include<QMessageBox>

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
    void on_yesButton_clicked();

private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
