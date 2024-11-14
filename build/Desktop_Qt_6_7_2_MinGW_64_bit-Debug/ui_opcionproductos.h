/********************************************************************************
** Form generated from reading UI file 'opcionproductos.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPCIONPRODUCTOS_H
#define UI_OPCIONPRODUCTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
            opcionProductos->setObjectName("opcionProductos");
        opcionProductos->resize(1343, 136);
        gridLayout = new QGridLayout(opcionProductos);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(opcionProductos);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbtAgInventario = new QPushButton(opcionProductos);
        pbtAgInventario->setObjectName("pbtAgInventario");
        QFont font1;
        font1.setPointSize(14);
        pbtAgInventario->setFont(font1);

        horizontalLayout->addWidget(pbtAgInventario);

        btnAgNuevoProd = new QPushButton(opcionProductos);
        btnAgNuevoProd->setObjectName("btnAgNuevoProd");
        btnAgNuevoProd->setFont(font1);

        horizontalLayout->addWidget(btnAgNuevoProd);

        btnModificarProd = new QPushButton(opcionProductos);
        btnModificarProd->setObjectName("btnModificarProd");
        btnModificarProd->setFont(font1);

        horizontalLayout->addWidget(btnModificarProd);

        pbtBorrarFac = new QPushButton(opcionProductos);
        pbtBorrarFac->setObjectName("pbtBorrarFac");
        pbtBorrarFac->setFont(font1);

        horizontalLayout->addWidget(pbtBorrarFac);

        pbtNumFac = new QPushButton(opcionProductos);
        pbtNumFac->setObjectName("pbtNumFac");
        pbtNumFac->setFont(font1);

        horizontalLayout->addWidget(pbtNumFac);

        pbtAgregarCliente = new QPushButton(opcionProductos);
        pbtAgregarCliente->setObjectName("pbtAgregarCliente");
        pbtAgregarCliente->setFont(font1);

        horizontalLayout->addWidget(pbtAgregarCliente);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        pushButton = new QPushButton(opcionProductos);
        pushButton->setObjectName("pushButton");
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        pushButton->setFont(font2);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(opcionProductos);

        QMetaObject::connectSlotsByName(opcionProductos);
    } // setupUi

    void retranslateUi(QDialog *opcionProductos)
    {
        opcionProductos->setWindowTitle(QCoreApplication::translate("opcionProductos", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("opcionProductos", "Opciones:", nullptr));
        pbtAgInventario->setText(QCoreApplication::translate("opcionProductos", "Agregar inventario", nullptr));
        btnAgNuevoProd->setText(QCoreApplication::translate("opcionProductos", "Agregar nuevo producto", nullptr));
        btnModificarProd->setText(QCoreApplication::translate("opcionProductos", "Modificar producto", nullptr));
        pbtBorrarFac->setText(QCoreApplication::translate("opcionProductos", "Borrar facturas", nullptr));
        pbtNumFac->setText(QCoreApplication::translate("opcionProductos", "Establecer n\303\272mero de facturas", nullptr));
        pbtAgregarCliente->setText(QCoreApplication::translate("opcionProductos", "Agregar cliente", nullptr));
        pushButton->setText(QCoreApplication::translate("opcionProductos", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class opcionProductos: public Ui_opcionProductos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPCIONPRODUCTOS_H
