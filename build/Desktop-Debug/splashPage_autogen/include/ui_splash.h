/********************************************************************************
** Form generated from reading UI file 'splash.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASH_H
#define UI_SPLASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_splash
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *splash)
    {
        if (splash->objectName().isEmpty())
            splash->setObjectName("splash");
        splash->resize(800, 600);
        centralwidget = new QWidget(splash);
        centralwidget->setObjectName("centralwidget");
        splash->setCentralWidget(centralwidget);
        menubar = new QMenuBar(splash);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        splash->setMenuBar(menubar);
        statusbar = new QStatusBar(splash);
        statusbar->setObjectName("statusbar");
        splash->setStatusBar(statusbar);

        retranslateUi(splash);

        QMetaObject::connectSlotsByName(splash);
    } // setupUi

    void retranslateUi(QMainWindow *splash)
    {
        splash->setWindowTitle(QCoreApplication::translate("splash", "splash", nullptr));
    } // retranslateUi

};

namespace Ui {
    class splash: public Ui_splash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASH_H
