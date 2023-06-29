#ifndef MYHISTORYDIALOG_H
#define MYHISTORYDIALOG_H

#include <QDialog>
#include "CHistogram.h"
#include <QVector>

namespace Ui {
class myHistoryDialog;
}

class myHistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myHistoryDialog(QWidget *parent = nullptr);

    //自己写的构造，包含所有数据
    explicit myHistoryDialog(int maximumUpCount,QVector<QString> taskNameVector,QVector<int> taskCountVector,int nullCount,QWidget *parent = nullptr);

    ~myHistoryDialog();

    //图表成员，要附在dialog上的
    CHistogram *m_pH;

private:
    Ui::myHistoryDialog *ui;
};

#endif // MYHISTORYDIALOG_H
