/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QMenu *addMenu;
    QMenu *returnMenu;
    QMenu *menulogo;
    QMenu *historyMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(793, 600);
        QFont font;
        font.setItalic(true);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8("plant.ico"), QSize(), QIcon::Selected, QIcon::On);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 811, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 793, 21));
        addMenu = new QMenu(menubar);
        addMenu->setObjectName(QString::fromUtf8("addMenu"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setBold(true);
        font1.setItalic(false);
        addMenu->setFont(font1);
        returnMenu = new QMenu(menubar);
        returnMenu->setObjectName(QString::fromUtf8("returnMenu"));
        menulogo = new QMenu(menubar);
        menulogo->setObjectName(QString::fromUtf8("menulogo"));
        historyMenu = new QMenu(menubar);
        historyMenu->setObjectName(QString::fromUtf8("historyMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(returnMenu->menuAction());
        menubar->addAction(menulogo->menuAction());
        menubar->addAction(historyMenu->menuAction());
        menubar->addAction(addMenu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addMenu->setTitle(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        returnMenu->setTitle(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        menulogo->setTitle(QCoreApplication::translate("MainWindow", "logo", nullptr));
        historyMenu->setTitle(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
