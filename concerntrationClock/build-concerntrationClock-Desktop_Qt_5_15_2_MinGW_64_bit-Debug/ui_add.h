/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add
{
public:
    QLabel *thingLabel;
    QLabel *timeLabel;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QLabel *tipLabel;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QWidget *Add)
    {
        if (Add->objectName().isEmpty())
            Add->setObjectName(QString::fromUtf8("Add"));
        Add->resize(294, 238);
        thingLabel = new QLabel(Add);
        thingLabel->setObjectName(QString::fromUtf8("thingLabel"));
        thingLabel->setGeometry(QRect(20, 50, 51, 21));
        timeLabel = new QLabel(Add);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(20, 80, 81, 21));
        lineEdit = new QLineEdit(Add);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 50, 181, 23));
        spinBox = new QSpinBox(Add);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(100, 80, 81, 24));
        spinBox->setMaximum(180);
        spinBox->setSingleStep(30);
        tipLabel = new QLabel(Add);
        tipLabel->setObjectName(QString::fromUtf8("tipLabel"));
        tipLabel->setGeometry(QRect(30, 120, 201, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        tipLabel->setFont(font);
        buttonBox = new QDialogButtonBox(Add);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 180, 161, 31));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Add);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 54, 16));

        retranslateUi(Add);

        QMetaObject::connectSlotsByName(Add);
    } // setupUi

    void retranslateUi(QWidget *Add)
    {
        Add->setWindowTitle(QCoreApplication::translate("Add", "Form", nullptr));
        thingLabel->setText(QCoreApplication::translate("Add", "\344\270\223\346\263\250\344\272\213\344\273\266", nullptr));
        timeLabel->setText(QCoreApplication::translate("Add", "\344\270\223\346\263\250\346\227\266\351\227\264(min)", nullptr));
        tipLabel->setText(QCoreApplication::translate("Add", "\346\202\250\345\260\206\344\270\223\346\263\25025\345\210\206\351\222\237\357\274\214\344\274\221\346\201\2575\345\210\206\351\222\237", nullptr));
        label->setText(QCoreApplication::translate("Add", "\344\270\223\346\263\250\346\230\237\347\220\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add: public Ui_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
