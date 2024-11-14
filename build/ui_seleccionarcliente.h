/********************************************************************************
** Form generated from reading UI file 'seleccionarcliente.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECCIONARCLIENTE_H
#define UI_SELECCIONARCLIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_SeleccionarCliente
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTableView *tvwClientes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SeleccionarCliente)
    {
        if (SeleccionarCliente->objectName().isEmpty())
            SeleccionarCliente->setObjectName(QStringLiteral("SeleccionarCliente"));
        SeleccionarCliente->resize(776, 473);
        gridLayout = new QGridLayout(SeleccionarCliente);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(SeleccionarCliente);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tvwClientes = new QTableView(SeleccionarCliente);
        tvwClientes->setObjectName(QStringLiteral("tvwClientes"));
        QFont font1;
        font1.setPointSize(14);
        tvwClientes->setFont(font1);

        gridLayout->addWidget(tvwClientes, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SeleccionarCliente);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(SeleccionarCliente);

        QMetaObject::connectSlotsByName(SeleccionarCliente);
    } // setupUi

    void retranslateUi(QDialog *SeleccionarCliente)
    {
        SeleccionarCliente->setWindowTitle(QApplication::translate("SeleccionarCliente", "Dialog", 0));
        label->setText(QApplication::translate("SeleccionarCliente", "Seleccione el cliente", 0));
    } // retranslateUi

};

namespace Ui {
    class SeleccionarCliente: public Ui_SeleccionarCliente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECCIONARCLIENTE_H
