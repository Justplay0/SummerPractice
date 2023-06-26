/********************************************************************************
** Form generated from reading UI file 'addnew_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEW_WIDGET_H
#define UI_ADDNEW_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNew_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_AddNewCancel;
    QSpinBox *sb_ConcentrationTime;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *le_TaskName;
    QPushButton *btn_AddNewConfirm;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_2;

    void setupUi(QWidget *AddNew_Widget)
    {
        if (AddNew_Widget->objectName().isEmpty())
            AddNew_Widget->setObjectName(QString::fromUtf8("AddNew_Widget"));
        AddNew_Widget->resize(550, 350);
        AddNew_Widget->setMinimumSize(QSize(550, 350));
        AddNew_Widget->setMaximumSize(QSize(550, 350));
        horizontalLayout = new QHBoxLayout(AddNew_Widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(AddNew_Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(100, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 0, 1, 1);

        btn_AddNewCancel = new QPushButton(widget);
        btn_AddNewCancel->setObjectName(QString::fromUtf8("btn_AddNewCancel"));

        gridLayout->addWidget(btn_AddNewCancel, 4, 3, 1, 1);

        sb_ConcentrationTime = new QSpinBox(widget);
        sb_ConcentrationTime->setObjectName(QString::fromUtf8("sb_ConcentrationTime"));

        gridLayout->addWidget(sb_ConcentrationTime, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(50, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        le_TaskName = new QLineEdit(widget);
        le_TaskName->setObjectName(QString::fromUtf8("le_TaskName"));

        gridLayout->addWidget(le_TaskName, 1, 2, 1, 1);

        btn_AddNewConfirm = new QPushButton(widget);
        btn_AddNewConfirm->setObjectName(QString::fromUtf8("btn_AddNewConfirm"));

        gridLayout->addWidget(btn_AddNewConfirm, 4, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(100, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(50, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 1, 4, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 2, 4, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 3, 4, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 4, 4, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 4, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 3, 1, 1, 3);


        horizontalLayout->addWidget(widget);


        retranslateUi(AddNew_Widget);

        QMetaObject::connectSlotsByName(AddNew_Widget);
    } // setupUi

    void retranslateUi(QWidget *AddNew_Widget)
    {
        AddNew_Widget->setWindowTitle(QApplication::translate("AddNew_Widget", "Form", nullptr));
        btn_AddNewCancel->setText(QApplication::translate("AddNew_Widget", "\345\217\226\346\266\210", nullptr));
        btn_AddNewConfirm->setText(QApplication::translate("AddNew_Widget", "\347\241\256\345\256\232", nullptr));
        label_3->setText(QApplication::translate("AddNew_Widget", "\344\273\273\345\212\241\345\220\215", nullptr));
        label_4->setText(QApplication::translate("AddNew_Widget", "\344\270\223\346\263\250\346\227\266\351\227\264", nullptr));
        label->setText(QApplication::translate("AddNew_Widget", "\344\273\273\345\212\241\346\267\273\345\212\240", nullptr));
        label_2->setText(QApplication::translate("AddNew_Widget", "\346\257\217\344\270\223\346\263\25025\345\210\206\351\222\237\357\274\214\345\260\206\344\274\232\344\274\221\346\201\2575\345\210\206\351\222\237\357\274\214\345\242\236\345\212\240\344\270\200\344\270\252\347\242\216\347\211\207\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNew_Widget: public Ui_AddNew_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEW_WIDGET_H
