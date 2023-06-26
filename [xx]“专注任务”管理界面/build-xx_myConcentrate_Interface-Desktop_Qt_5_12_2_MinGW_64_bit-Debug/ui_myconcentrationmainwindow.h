/********************************************************************************
** Form generated from reading UI file 'myconcentrationmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCONCENTRATIONMAINWINDOW_H
#define UI_MYCONCENTRATIONMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyConcentrationMainWindow
{
public:
    QAction *action_turnBack;
    QAction *action_addNew;
    QAction *action_other;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *mainWindow_returnBtn;
    QPushButton *mainWindow_addNewBtn;
    QPushButton *mainWindow_historyBtn;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *labelStart_3;
    QPushButton *labelDelete_2;
    QPushButton *labelStart_1;
    QPushButton *labelDelete_4;
    QPushButton *labelStart_6;
    QPushButton *labelStart_2;
    QLabel *taskLabel_1;
    QLabel *taskLabel_4;
    QPushButton *labelStart_4;
    QPushButton *labelDelete_3;
    QPushButton *labelDelete_1;
    QPushButton *labelDelete_6;
    QLabel *taskLabel_7;
    QPushButton *labelDelete_5;
    QLabel *taskLabel_2;
    QLabel *taskLabel_3;
    QPushButton *labelStart_5;
    QLabel *taskLabel_6;
    QLabel *taskLabel_5;
    QPushButton *labelStart_7;
    QPushButton *labelDelete_7;

    void setupUi(QMainWindow *MyConcentrationMainWindow)
    {
        if (MyConcentrationMainWindow->objectName().isEmpty())
            MyConcentrationMainWindow->setObjectName(QString::fromUtf8("MyConcentrationMainWindow"));
        MyConcentrationMainWindow->resize(600, 600);
        MyConcentrationMainWindow->setMinimumSize(QSize(600, 600));
        MyConcentrationMainWindow->setMaximumSize(QSize(600, 600));
        action_turnBack = new QAction(MyConcentrationMainWindow);
        action_turnBack->setObjectName(QString::fromUtf8("action_turnBack"));
        action_addNew = new QAction(MyConcentrationMainWindow);
        action_addNew->setObjectName(QString::fromUtf8("action_addNew"));
        action_other = new QAction(MyConcentrationMainWindow);
        action_other->setObjectName(QString::fromUtf8("action_other"));
        centralWidget = new QWidget(MyConcentrationMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(4, -16, 591, 101));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        mainWindow_returnBtn = new QPushButton(gridLayoutWidget);
        mainWindow_returnBtn->setObjectName(QString::fromUtf8("mainWindow_returnBtn"));
        mainWindow_returnBtn->setMinimumSize(QSize(100, 50));
        mainWindow_returnBtn->setMaximumSize(QSize(100, 50));

        gridLayout_3->addWidget(mainWindow_returnBtn, 0, 0, 1, 1);

        mainWindow_addNewBtn = new QPushButton(gridLayoutWidget);
        mainWindow_addNewBtn->setObjectName(QString::fromUtf8("mainWindow_addNewBtn"));
        mainWindow_addNewBtn->setMinimumSize(QSize(100, 50));
        mainWindow_addNewBtn->setMaximumSize(QSize(100, 50));

        gridLayout_3->addWidget(mainWindow_addNewBtn, 0, 2, 1, 1);

        mainWindow_historyBtn = new QPushButton(gridLayoutWidget);
        mainWindow_historyBtn->setObjectName(QString::fromUtf8("mainWindow_historyBtn"));
        mainWindow_historyBtn->setMinimumSize(QSize(100, 50));
        mainWindow_historyBtn->setMaximumSize(QSize(100, 50));

        gridLayout_3->addWidget(mainWindow_historyBtn, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 60, 591, 521));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelStart_3 = new QPushButton(widget);
        labelStart_3->setObjectName(QString::fromUtf8("labelStart_3"));
        labelStart_3->setMinimumSize(QSize(100, 0));
        labelStart_3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelStart_3, 2, 1, 1, 1);

        labelDelete_2 = new QPushButton(widget);
        labelDelete_2->setObjectName(QString::fromUtf8("labelDelete_2"));
        labelDelete_2->setMinimumSize(QSize(100, 0));
        labelDelete_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDelete_2, 1, 2, 1, 1);

        labelStart_1 = new QPushButton(widget);
        labelStart_1->setObjectName(QString::fromUtf8("labelStart_1"));
        labelStart_1->setMinimumSize(QSize(100, 0));
        labelStart_1->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelStart_1, 0, 1, 1, 1);

        labelDelete_4 = new QPushButton(widget);
        labelDelete_4->setObjectName(QString::fromUtf8("labelDelete_4"));
        labelDelete_4->setMinimumSize(QSize(100, 0));
        labelDelete_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDelete_4, 3, 2, 1, 1);

        labelStart_6 = new QPushButton(widget);
        labelStart_6->setObjectName(QString::fromUtf8("labelStart_6"));
        labelStart_6->setMinimumSize(QSize(100, 0));
        labelStart_6->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelStart_6, 5, 1, 1, 1);

        labelStart_2 = new QPushButton(widget);
        labelStart_2->setObjectName(QString::fromUtf8("labelStart_2"));
        labelStart_2->setMinimumSize(QSize(100, 0));
        labelStart_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelStart_2, 1, 1, 1, 1);

        taskLabel_1 = new QLabel(widget);
        taskLabel_1->setObjectName(QString::fromUtf8("taskLabel_1"));

        gridLayout->addWidget(taskLabel_1, 0, 0, 1, 1);

        taskLabel_4 = new QLabel(widget);
        taskLabel_4->setObjectName(QString::fromUtf8("taskLabel_4"));

        gridLayout->addWidget(taskLabel_4, 3, 0, 1, 1);

        labelStart_4 = new QPushButton(widget);
        labelStart_4->setObjectName(QString::fromUtf8("labelStart_4"));
        labelStart_4->setMinimumSize(QSize(100, 0));
        labelStart_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelStart_4, 3, 1, 1, 1);

        labelDelete_3 = new QPushButton(widget);
        labelDelete_3->setObjectName(QString::fromUtf8("labelDelete_3"));
        labelDelete_3->setMinimumSize(QSize(100, 0));
        labelDelete_3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDelete_3, 2, 2, 1, 1);

        labelDelete_1 = new QPushButton(widget);
        labelDelete_1->setObjectName(QString::fromUtf8("labelDelete_1"));
        labelDelete_1->setMinimumSize(QSize(100, 0));
        labelDelete_1->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDelete_1, 0, 2, 1, 1);

        labelDelete_6 = new QPushButton(widget);
        labelDelete_6->setObjectName(QString::fromUtf8("labelDelete_6"));
        labelDelete_6->setMinimumSize(QSize(100, 0));
        labelDelete_6->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDelete_6, 5, 2, 1, 1);

        taskLabel_7 = new QLabel(widget);
        taskLabel_7->setObjectName(QString::fromUtf8("taskLabel_7"));

        gridLayout->addWidget(taskLabel_7, 6, 0, 1, 1);

        labelDelete_5 = new QPushButton(widget);
        labelDelete_5->setObjectName(QString::fromUtf8("labelDelete_5"));
        labelDelete_5->setMinimumSize(QSize(100, 0));
        labelDelete_5->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDelete_5, 4, 2, 1, 1);

        taskLabel_2 = new QLabel(widget);
        taskLabel_2->setObjectName(QString::fromUtf8("taskLabel_2"));

        gridLayout->addWidget(taskLabel_2, 1, 0, 1, 1);

        taskLabel_3 = new QLabel(widget);
        taskLabel_3->setObjectName(QString::fromUtf8("taskLabel_3"));

        gridLayout->addWidget(taskLabel_3, 2, 0, 1, 1);

        labelStart_5 = new QPushButton(widget);
        labelStart_5->setObjectName(QString::fromUtf8("labelStart_5"));
        labelStart_5->setMinimumSize(QSize(100, 0));
        labelStart_5->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelStart_5, 4, 1, 1, 1);

        taskLabel_6 = new QLabel(widget);
        taskLabel_6->setObjectName(QString::fromUtf8("taskLabel_6"));

        gridLayout->addWidget(taskLabel_6, 5, 0, 1, 1);

        taskLabel_5 = new QLabel(widget);
        taskLabel_5->setObjectName(QString::fromUtf8("taskLabel_5"));

        gridLayout->addWidget(taskLabel_5, 4, 0, 1, 1);

        labelStart_7 = new QPushButton(widget);
        labelStart_7->setObjectName(QString::fromUtf8("labelStart_7"));
        labelStart_7->setMinimumSize(QSize(100, 0));
        labelStart_7->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelStart_7, 6, 1, 1, 1);

        labelDelete_7 = new QPushButton(widget);
        labelDelete_7->setObjectName(QString::fromUtf8("labelDelete_7"));
        labelDelete_7->setMinimumSize(QSize(100, 0));
        labelDelete_7->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(labelDelete_7, 6, 2, 1, 1);

        MyConcentrationMainWindow->setCentralWidget(centralWidget);

        retranslateUi(MyConcentrationMainWindow);

        QMetaObject::connectSlotsByName(MyConcentrationMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyConcentrationMainWindow)
    {
        MyConcentrationMainWindow->setWindowTitle(QApplication::translate("MyConcentrationMainWindow", "MyConcentrationMainWindow", nullptr));
        action_turnBack->setText(QApplication::translate("MyConcentrationMainWindow", "\350\277\224\345\233\236", nullptr));
        action_addNew->setText(QApplication::translate("MyConcentrationMainWindow", "\346\267\273\345\212\240", nullptr));
        action_other->setText(QApplication::translate("MyConcentrationMainWindow", "\345\205\266\344\273\226", nullptr));
        mainWindow_returnBtn->setText(QApplication::translate("MyConcentrationMainWindow", "\350\277\224\345\233\236", nullptr));
        mainWindow_addNewBtn->setText(QApplication::translate("MyConcentrationMainWindow", "\346\267\273\345\212\240", nullptr));
        mainWindow_historyBtn->setText(QApplication::translate("MyConcentrationMainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        labelStart_3->setText(QApplication::translate("MyConcentrationMainWindow", "\345\274\200\345\247\213", nullptr));
        labelDelete_2->setText(QApplication::translate("MyConcentrationMainWindow", "\345\210\240\351\231\244", nullptr));
        labelStart_1->setText(QApplication::translate("MyConcentrationMainWindow", "\345\274\200\345\247\213", nullptr));
        labelDelete_4->setText(QApplication::translate("MyConcentrationMainWindow", "\345\210\240\351\231\244", nullptr));
        labelStart_6->setText(QApplication::translate("MyConcentrationMainWindow", "\345\274\200\345\247\213", nullptr));
        labelStart_2->setText(QApplication::translate("MyConcentrationMainWindow", "\345\274\200\345\247\213", nullptr));
        taskLabel_1->setText(QString());
        taskLabel_4->setText(QString());
        labelStart_4->setText(QApplication::translate("MyConcentrationMainWindow", "\345\274\200\345\247\213", nullptr));
        labelDelete_3->setText(QApplication::translate("MyConcentrationMainWindow", "\345\210\240\351\231\244", nullptr));
        labelDelete_1->setText(QApplication::translate("MyConcentrationMainWindow", "\345\210\240\351\231\244", nullptr));
        labelDelete_6->setText(QApplication::translate("MyConcentrationMainWindow", "\345\210\240\351\231\244", nullptr));
        taskLabel_7->setText(QString());
        labelDelete_5->setText(QApplication::translate("MyConcentrationMainWindow", "\345\210\240\351\231\244", nullptr));
        taskLabel_2->setText(QString());
        taskLabel_3->setText(QString());
        labelStart_5->setText(QApplication::translate("MyConcentrationMainWindow", "\345\274\200\345\247\213", nullptr));
        taskLabel_6->setText(QString());
        taskLabel_5->setText(QString());
        labelStart_7->setText(QApplication::translate("MyConcentrationMainWindow", "\345\274\200\345\247\213", nullptr));
        labelDelete_7->setText(QApplication::translate("MyConcentrationMainWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyConcentrationMainWindow: public Ui_MyConcentrationMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCONCENTRATIONMAINWINDOW_H
