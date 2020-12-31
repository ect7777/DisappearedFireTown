/********************************************************************************
** Form generated from reading UI file 'dft.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DFT_H
#define UI_DFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DFT
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DFT)
    {
        if (DFT->objectName().isEmpty())
            DFT->setObjectName(QString::fromUtf8("DFT"));
        DFT->resize(1440, 900);
        centralwidget = new QWidget(DFT);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1250, 800, 181, 28));
        DFT->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DFT);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1440, 26));
        DFT->setMenuBar(menubar);
        statusbar = new QStatusBar(DFT);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DFT->setStatusBar(statusbar);

        retranslateUi(DFT);

        QMetaObject::connectSlotsByName(DFT);
    } // setupUi

    void retranslateUi(QMainWindow *DFT)
    {
        DFT->setWindowTitle(QCoreApplication::translate("DFT", "DFT", nullptr));
        pushButton->setText(QCoreApplication::translate("DFT", "hahahah", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DFT: public Ui_DFT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFT_H
