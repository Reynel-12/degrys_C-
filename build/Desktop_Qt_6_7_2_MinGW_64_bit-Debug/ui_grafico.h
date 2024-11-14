/********************************************************************************
** Form generated from reading UI file 'grafico.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICO_H
#define UI_GRAFICO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_grafico
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QCustomPlot *widget;

    void setupUi(QDialog *grafico)
    {
        if (grafico->objectName().isEmpty())
            grafico->setObjectName("grafico");
        grafico->resize(1143, 688);
        gridLayout = new QGridLayout(grafico);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(grafico);
        pushButton->setObjectName("pushButton");
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        widget = new QCustomPlot(grafico);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(grafico);

        QMetaObject::connectSlotsByName(grafico);
    } // setupUi

    void retranslateUi(QDialog *grafico)
    {
        grafico->setWindowTitle(QCoreApplication::translate("grafico", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("grafico", "Generar reporte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class grafico: public Ui_grafico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICO_H
