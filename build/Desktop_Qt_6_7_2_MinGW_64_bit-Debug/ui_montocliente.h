/********************************************************************************
** Form generated from reading UI file 'montocliente.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTOCLIENTE_H
#define UI_MONTOCLIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_montoCliente
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *letMonto;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *letTotal;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *letCambio;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *montoCliente)
    {
        if (montoCliente->objectName().isEmpty())
            montoCliente->setObjectName("montoCliente");
        montoCliente->resize(521, 188);
        gridLayout = new QGridLayout(montoCliente);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(montoCliente);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        letMonto = new QLineEdit(montoCliente);
        letMonto->setObjectName("letMonto");
        QFont font1;
        font1.setPointSize(14);
        letMonto->setFont(font1);

        horizontalLayout->addWidget(letMonto);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(montoCliente);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        letTotal = new QLineEdit(montoCliente);
        letTotal->setObjectName("letTotal");
        letTotal->setFont(font1);

        horizontalLayout_2->addWidget(letTotal);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(montoCliente);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        letCambio = new QLineEdit(montoCliente);
        letCambio->setObjectName("letCambio");
        letCambio->setFont(font1);

        horizontalLayout_3->addWidget(letCambio);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(montoCliente);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);


        retranslateUi(montoCliente);

        QMetaObject::connectSlotsByName(montoCliente);
    } // setupUi

    void retranslateUi(QDialog *montoCliente)
    {
        montoCliente->setWindowTitle(QCoreApplication::translate("montoCliente", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("montoCliente", "Ingrese el monto a cancelar:", nullptr));
        label_2->setText(QCoreApplication::translate("montoCliente", "Total:", nullptr));
        letTotal->setText(QString());
        label_3->setText(QCoreApplication::translate("montoCliente", "Saldo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class montoCliente: public Ui_montoCliente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTOCLIENTE_H
