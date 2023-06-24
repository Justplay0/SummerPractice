/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *planet1;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_24;
    QLabel *dot6;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_28;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_25;
    QLabel *dot3;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_30;
    QLabel *dot5;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_26;
    QLabel *planet4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_19;
    QLabel *planet3;
    QLabel *dot4;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *horizontalSpacer_29;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QLabel *planet2;
    QSpacerItem *horizontalSpacer_27;
    QSpacerItem *horizontalSpacer_20;
    QLabel *dot2;
    QLabel *dot1;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(375, 200);
        Widget->setMinimumSize(QSize(375, 200));
        Widget->setMaximumSize(QSize(375, 200));
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        planet1 = new QLabel(widget);
        planet1->setObjectName(QString::fromUtf8("planet1"));
        planet1->setMinimumSize(QSize(20, 20));
        planet1->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(planet1, 5, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 4, 2, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_24, 0, 1, 1, 1);

        dot6 = new QLabel(widget);
        dot6->setObjectName(QString::fromUtf8("dot6"));
        dot6->setMinimumSize(QSize(20, 20));
        dot6->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(dot6, 2, 8, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 5, 9, 1, 1);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_28, 0, 6, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 4, 4, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_17, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 4, 1, 1);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_25, 0, 2, 1, 1);

        dot3 = new QLabel(widget);
        dot3->setObjectName(QString::fromUtf8("dot3"));
        dot3->setMinimumSize(QSize(20, 20));
        dot3->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(dot3, 2, 4, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_21, 2, 7, 1, 1);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_30, 0, 8, 1, 1);

        dot5 = new QLabel(widget);
        dot5->setObjectName(QString::fromUtf8("dot5"));
        dot5->setMinimumSize(QSize(20, 20));
        dot5->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(dot5, 4, 7, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 4, 3, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 4, 8, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 5, 2, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_26, 0, 4, 1, 1);

        planet4 = new QLabel(widget);
        planet4->setObjectName(QString::fromUtf8("planet4"));
        planet4->setMinimumSize(QSize(20, 20));
        planet4->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(planet4, 0, 9, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 5, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_19, 2, 5, 1, 1);

        planet3 = new QLabel(widget);
        planet3->setObjectName(QString::fromUtf8("planet3"));
        planet3->setMinimumSize(QSize(20, 20));
        planet3->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(planet3, 5, 6, 1, 1);

        dot4 = new QLabel(widget);
        dot4->setObjectName(QString::fromUtf8("dot4"));
        dot4->setMinimumSize(QSize(20, 20));
        dot4->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(dot4, 4, 5, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_23, 0, 0, 1, 1);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_29, 0, 7, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 2, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 4, 9, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_16, 4, 0, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_22, 2, 9, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_18, 2, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 4, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 7, 1, 1);

        planet2 = new QLabel(widget);
        planet2->setObjectName(QString::fromUtf8("planet2"));
        planet2->setMinimumSize(QSize(20, 20));
        planet2->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(planet2, 0, 3, 1, 1);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_27, 0, 5, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_20, 2, 6, 1, 1);

        dot2 = new QLabel(widget);
        dot2->setObjectName(QString::fromUtf8("dot2"));
        dot2->setMinimumSize(QSize(20, 20));
        dot2->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(dot2, 2, 2, 1, 1);

        dot1 = new QLabel(widget);
        dot1->setObjectName(QString::fromUtf8("dot1"));
        dot1->setMinimumSize(QSize(20, 20));
        dot1->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(dot1, 4, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 5, 8, 1, 1);


        horizontalLayout->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\210\220\345\260\261\347\225\214\351\235\242", nullptr));
        planet1->setText(QApplication::translate("Widget", "p1", nullptr));
        dot6->setText(QApplication::translate("Widget", "d6", nullptr));
        dot3->setText(QApplication::translate("Widget", "d3", nullptr));
        dot5->setText(QApplication::translate("Widget", "d5", nullptr));
        planet4->setText(QApplication::translate("Widget", "p4", nullptr));
        planet3->setText(QApplication::translate("Widget", "p3", nullptr));
        dot4->setText(QApplication::translate("Widget", "d4", nullptr));
        planet2->setText(QApplication::translate("Widget", "p2", nullptr));
        dot2->setText(QApplication::translate("Widget", "d2", nullptr));
        dot1->setText(QApplication::translate("Widget", "d1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
