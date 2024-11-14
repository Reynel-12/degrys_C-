/********************************************************************************
** Form generated from reading UI file 'opcionproductos.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPCIONPRODUCTOS_H
#define UI_OPCIONPRODUCTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_opcionProductos
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbtAgInventario;
    QPushButton *btnAgNuevoProd;
    QPushButton *btnModificarProd;
    QPushButton *pbtBorrarFac;
    QPushButton *pbtNumFac;
    QPushButton *pbtAgregarCliente;
    QPushButton *pushButton;

    void setupUi(QDialog *opcionProductos)
    {
        if (opcionProductos->objectName().isEmpty())
            opcionProductos->setObjectName(QStringLiteral("opcionProductos"));
        opcionProductos->resize(1343, 136);
        gridLayout = new QGridLayout(opcionProductos);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(opcionProductos);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbtAgInventario = new QPushButton(opcionProductos);
        pbtAgInventario->setObjectName(QStringLiteral("pbtAgInventario"));
        QFont font1;
        font1.setPointSize(14);
        pbtAgInventario->setFont(font1);

        horizontalLayout->addWidget(pbtAgInventario);

        btnAgNuevoProd = new QPushButton(opcionProductos);
        btnAgNuevoProd->setObjectName(QStringLiteral("btnAgNuevoProd"));
        btnAgNuevoProd->setFont(font1);

        horizontalLayout->addWidget(btnAgNuevoProd);

        btnModificarProd = new QPushButton(opcionProductos);
        btnModificarProd->setObjectName(QStringLiteral("btnModificarProd"));
        btnModificarProd->setFont(font1);

        horizontalLayout->addWidget(btnModificarProd);

        pbtBorrarFac = new QPushButton(opcionProductos);
        pbtBorrarFac->setObjectName(QStringLiteral("pbtBorrarFac"));
        pbtBorrarFac->setFont(font1);

        horizontalLayout->addWidget(pbtBorrarFac);

        pbtNumFac = new QPushButton(opcionProductos);
        pbtNumFac->setObjectName(QStringLiteral("pbtNumFac"));
        pbtNumFac->setFont(font1);

        horizontalLayout->addWidget(pbtNumFac);

        pbtAgregarCliente = new QPushButton(opcionProductos);
        pbtAgregarCliente->setObjectName(QStringLiteral("pbtAgregarCliente"));
        pbtAgregarCliente->setFont(font1);

        horizontalLayout->addWidget(pbtAgregarCliente);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        pushButton = new QPushButton(opcionProductos);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(opcionProductos);

        QMetaObject::connectSlotsByName(opcionProductos);
    } // setupUi

    void retranslateUi(QDialog *opcionProductos)
    {
        opcionProductos->setWindowTitle(QApplication::translate("opcionProductos", "Dialog", 0));
        label->setText(QApplication::translate("opcionProductos", "Opciones:", 0));
        pbtAgInventario->setText(QApplication::translate("opcionProductos", "Agregar inventario", 0));
        btnAgNuevoProd->setText(QApplication::translate("opcionProductos", "Agregar nuevo producto", 0));
        btnModificarProd->setText(QApplication::translate("opcionProductos", "Modificar producto", 0));
        pbtBorrarFac->setText(QApplication::translate("opcionProductos", "Borrar facturas", 0));
        pbtNumFac->setText(QApplication::translate("opcionProductos", "Establecer n\303\272mero de facturas", 0));
        pbtAgregarCliente->setText(QApplication::translate("opcionProductos", "Agregar cliente", 0));
        pushButton->setText(QApplication::translate("opcionProductos", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class opcionProductos: public Ui_opcionProductos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPCIONPRODUCTOS_H
