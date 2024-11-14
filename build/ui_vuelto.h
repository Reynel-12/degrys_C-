/********************************************************************************
** Form generated from reading UI file 'vuelto.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VUELTO_H
#define UI_VUELTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            Vuelto->setObjectName(QStringLiteral("Vuelto"));
        Vuelto->resize(464, 222);
        gridLayout_2 = new QGridLayout(Vuelto);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Vuelto);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Vuelto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        label_3 = new QLabel(Vuelto);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 3);

        letTotal = new QLineEdit(Vuelto);
        letTotal->setObjectName(QStringLiteral("letTotal"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        letTotal->setFont(font1);

        gridLayout->addWidget(letTotal, 0, 1, 1, 3);

        letCambio = new QLineEdit(Vuelto);
        letCambio->setObjectName(QStringLiteral("letCambio"));
        letCambio->setFont(font1);

        gridLayout->addWidget(letCambio, 2, 3, 1, 1);

        letCliente = new QLineEdit(Vuelto);
        letCliente->setObjectName(QStringLiteral("letCliente"));
        letCliente->setFont(font1);

        gridLayout->addWidget(letCliente, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        btbConfir = new QDialogButtonBox(Vuelto);
        btbConfir->setObjectName(QStringLiteral("btbConfir"));
        btbConfir->setFont(font);
        btbConfir->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(btbConfir, 1, 0, 1, 1);


        retranslateUi(Vuelto);

        QMetaObject::connectSlotsByName(Vuelto);
    } // setupUi

    void retranslateUi(QDialog *Vuelto)
    {
        Vuelto->setWindowTitle(QApplication::translate("Vuelto", "Dialog", 0));
        label->setText(QApplication::translate("Vuelto", "Total:", 0));
        label_2->setText(QApplication::translate("Vuelto", "Cliente:", 0));
        label_3->setText(QApplication::translate("Vuelto", "Cambio:", 0));
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
