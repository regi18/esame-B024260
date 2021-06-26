/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *currentUploadingProgress;
    QProgressBar *totalNumberUploadedProgress;
    QLabel *label;
    QLabel *label_2;
    QPushButton *uploadFileButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(795, 364);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        currentUploadingProgress = new QProgressBar(centralwidget);
        currentUploadingProgress->setObjectName(QString::fromUtf8("currentUploadingProgress"));
        currentUploadingProgress->setGeometry(QRect(30, 70, 741, 23));
        currentUploadingProgress->setValue(24);
        totalNumberUploadedProgress = new QProgressBar(centralwidget);
        totalNumberUploadedProgress->setObjectName(QString::fromUtf8("totalNumberUploadedProgress"));
        totalNumberUploadedProgress->setGeometry(QRect(30, 150, 741, 23));
        totalNumberUploadedProgress->setMinimum(0);
        totalNumberUploadedProgress->setMaximum(3);
        totalNumberUploadedProgress->setValue(0);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 121, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 130, 121, 16));
        uploadFileButton = new QPushButton(centralwidget);
        uploadFileButton->setObjectName(QString::fromUtf8("uploadFileButton"));
        uploadFileButton->setGeometry(QRect(270, 230, 251, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 795, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Esame \"Laboratorio di Programmazione\"", nullptr));
        totalNumberUploadedProgress->setFormat(QApplication::translate("MainWindow", "%v/%m", nullptr));
        label->setText(QApplication::translate("MainWindow", "Current progress", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Total progress", nullptr));
        uploadFileButton->setText(QApplication::translate("MainWindow", "Upload file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
