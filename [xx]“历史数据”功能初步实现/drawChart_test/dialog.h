#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimerEvent>
#include "CHistogram.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    void timerEvent(QTimerEvent *event);

    CHistogram *m_pH;
};

#endif // DIALOG_H

