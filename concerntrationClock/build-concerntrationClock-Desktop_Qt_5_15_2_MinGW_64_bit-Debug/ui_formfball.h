/********************************************************************************
** Form generated from reading UI file 'formfball.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMFBALL_H
#define UI_FORMFBALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormFball
{
public:
    QLabel *label;

    void setupUi(QWidget *FormFball)
    {
        if (FormFball->objectName().isEmpty())
            FormFball->setObjectName(QString::fromUtf8("FormFball"));
        FormFball->resize(176, 133);
        label = new QLabel(FormFball);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 81, 41));

        retranslateUi(FormFball);

        QMetaObject::connectSlotsByName(FormFball);
    } // setupUi

    void retranslateUi(QWidget *FormFball)
    {
        FormFball->setWindowTitle(QCoreApplication::translate("FormFball", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormFball", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormFball: public Ui_FormFball {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMFBALL_H
