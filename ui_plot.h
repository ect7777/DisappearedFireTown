/********************************************************************************
** Form generated from reading UI file 'plot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOT_H
#define UI_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plot
{
public:

    void setupUi(QWidget *plot)
    {
        if (plot->objectName().isEmpty())
            plot->setObjectName(QString::fromUtf8("plot"));
        plot->resize(1440, 900);

        retranslateUi(plot);

        QMetaObject::connectSlotsByName(plot);
    } // setupUi

    void retranslateUi(QWidget *plot)
    {
        plot->setWindowTitle(QCoreApplication::translate("plot", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plot: public Ui_plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOT_H
