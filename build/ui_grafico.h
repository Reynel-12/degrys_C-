/********************************************************************************
** Form generated from reading UI file 'grafico.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICO_H
#define UI_GRAFICO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            grafico->setObjectName(QStringLiteral("grafico"));
        grafico->resize(1143, 688);
        gridLayout = new QGridLayout(grafico);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(grafico);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        widget = new QCustomPlot(grafico);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(grafico);

        QMetaObject::connectSlotsByName(grafico);
    } // setupUi

    void retranslateUi(QDialog *grafico)
    {
        grafico->setWindowTitle(QApplication::translate("grafico", "Dialog", 0));
        pushButton->setText(QApplication::translate("grafico", "Generar reporte", 0));
    } // retranslateUi

};

namespace Ui {
    class grafico: public Ui_grafico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICO_H
