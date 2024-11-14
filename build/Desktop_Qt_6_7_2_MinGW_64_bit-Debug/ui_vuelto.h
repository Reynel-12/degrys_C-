/********************************************************************************
** Form generated from reading UI file 'vuelto.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VUELTO_H
#define UI_VUELTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Vuelto
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *letTotal;
    QLineEdit *letCambio;
    QLineEdit *letCliente;
    QDialogButtonBox *btbConfir;

    void setupUi(QDialog *Vuelto)
    {
        if (Vuelto->objectName().isEmpty())
            Vuelto->setObjectName("Vuelto");
        Vuelto->resize(464, 222);
        gridLayout_2 = new QGridLayout(Vuelto);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Vuelto);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Vuelto);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        label_3 = new QLabel(Vuelto);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 3);

        letTotal = new QLineEdit(Vuelto);
        letTotal->setObjectName("letTotal");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        letTotal->setFont(font1);

        gridLayout->addWidget(letTotal, 0, 1, 1, 3);

        letCambio = new QLineEdit(Vuelto);
        letCambio->setObjectName("letCambio");
        letCambio->setFont(font1);

        gridLayout->addWidget(letCambio, 2, 3, 1, 1);

        letCliente = new QLineEdit(Vuelto);
        letCliente->setObjectName("letCliente");
        letCliente->setFont(font1);

        gridLayout->addWidget(letCliente, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        btbConfir = new QDialogButtonBox(Vuelto);
        btbConfir->setObjectName("btbConfir");
        btbConfir->setFont(font);
        btbConfir->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(btbConfir, 1, 0, 1, 1);


        retranslateUi(Vuelto);

        QMetaObject::connectSlotsByName(Vuelto);
    } // setupUi

    void retranslateUi(QDialog *Vuelto)
    {
        Vuelto->setWindowTitle(QCoreApplication::translate("Vuelto", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Vuelto", "Total:", nullptr));
        label_2->setText(QCoreApplication::translate("Vuelto", "Cliente:", nullptr));
        label_3->setText(QCoreApplication::translate("Vuelto", "Cambio:", nullptr));
        letTotal->setText(QString());
        letCambio->setText(QString());
        letCliente->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Vuelto: public Ui_Vuelto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VUELTO_H
