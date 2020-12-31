/********************************************************************************
** Form generated from reading UI file 'fightwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGHTWINDOW_H
#define UI_FIGHTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fightwindow
{
public:
    QPushButton *choose0;
    QPushButton *choose1;
    QPushButton *choose2;
    QPushButton *choose3;
    QPushButton *choose4;

    void setupUi(QWidget *Fightwindow)
    {
        if (Fightwindow->objectName().isEmpty())
            Fightwindow->setObjectName(QString::fromUtf8("Fightwindow"));
        Fightwindow->resize(1440, 900);
        choose0 = new QPushButton(Fightwindow);
        choose0->setObjectName(QString::fromUtf8("choose0"));
        choose0->setGeometry(QRect(0, 700, 288, 200));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        choose0->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        choose0->setFont(font);
        choose0->setStyleSheet(QString::fromUtf8("background-image: url(:/image/buttonbk.png);"));
        choose1 = new QPushButton(Fightwindow);
        choose1->setObjectName(QString::fromUtf8("choose1"));
        choose1->setGeometry(QRect(288, 700, 288, 200));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        choose1->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        choose1->setFont(font1);
        choose1->setStyleSheet(QString::fromUtf8("background-image: url(:/image/buttonbk.png);"));
        choose2 = new QPushButton(Fightwindow);
        choose2->setObjectName(QString::fromUtf8("choose2"));
        choose2->setGeometry(QRect(576, 700, 288, 200));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        choose2->setPalette(palette2);
        choose2->setFont(font1);
        choose2->setStyleSheet(QString::fromUtf8("background-image: url(:/image/buttonbk.png);"));
        choose3 = new QPushButton(Fightwindow);
        choose3->setObjectName(QString::fromUtf8("choose3"));
        choose3->setGeometry(QRect(864, 700, 288, 200));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        choose3->setPalette(palette3);
        choose3->setFont(font1);
        choose3->setStyleSheet(QString::fromUtf8("background-image: url(:/image/buttonbk.png);"));
        choose4 = new QPushButton(Fightwindow);
        choose4->setObjectName(QString::fromUtf8("choose4"));
        choose4->setGeometry(QRect(1152, 700, 288, 200));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        choose4->setPalette(palette4);
        choose4->setFont(font1);
        choose4->setStyleSheet(QString::fromUtf8("background-image: url(:/image/buttonbk.png);"));

        retranslateUi(Fightwindow);

        QMetaObject::connectSlotsByName(Fightwindow);
    } // setupUi

    void retranslateUi(QWidget *Fightwindow)
    {
        Fightwindow->setWindowTitle(QCoreApplication::translate("Fightwindow", "Form", nullptr));
        choose0->setText(QString());
        choose1->setText(QString());
        choose2->setText(QString());
        choose3->setText(QString());
        choose4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Fightwindow: public Ui_Fightwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGHTWINDOW_H
