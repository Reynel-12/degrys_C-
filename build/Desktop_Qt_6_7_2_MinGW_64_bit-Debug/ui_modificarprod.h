/********************************************************************************
** Form generated from reading UI file 'modificarprod.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARPROD_H
#define UI_MODIFICARPROD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_modificarProd
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbtCambiarCodigo;
    QPushButton *pbtCambiarNombre;
    QPushButton *pbtCambiarUnidad;
    QPushButton *CambiarPrecio;
    QPushButton *pbtEliminarProd;
    QPushButton *pbtSalir;

    void setupUi(QDialog *modificarProd)
    {
        if (modificarProd->objectName().isEmpty())
            modificarProd->setObjectName("modificarProd");
        modificarProd->resize(907, 136);
        gridLayout = new QGridLayout(modificarProd);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(modificarProd);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbtCambiarCodigo = new QPushButton(modificarProd);
        pbtCambiarCodigo->setObjectName("pbtCambiarCodigo");
        QFont font1;
        font1.setPointSize(14);
        pbtCambiarCodigo->setFont(font1);

        horizontalLayout->addWidget(pbtCambiarCodigo);

        pbtCambiarNombre = new QPushButton(modificarProd);
        pbtCambiarNombre->setObjectName("pbtCambiarNombre");
        pbtCambiarNombre->setFont(font1);

        horizontalLayout->addWidget(pbtCambiarNombre);

        pbtCambiarUnidad = new QPushButton(modificarProd);
        pbtCambiarUnidad->setObjectName("pbtCambiarUnidad");
        pbtCambiarUnidad->setFont(font1);

        horizontalLayout->addWidget(pbtCambiarUnidad);

        CambiarPrecio = new QPushButton(modificarProd);
        CambiarPrecio->setObjectName("CambiarPrecio");
        CambiarPrecio->setFont(font1);

        horizontalLayout->addWidget(CambiarPrecio);

        pbtEliminarProd = new QPushButton(modificarProd);
        pbtEliminarProd->setObjectName("pbtEliminarProd");
        pbtEliminarProd->setFont(font1);

        horizontalLayout->addWidget(pbtEliminarProd);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        pbtSalir = new QPushButton(modificarProd);
        pbtSalir->setObjectName("pbtSalir");
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        pbtSalir->setFont(font2);

        gridLayout->addWidget(pbtSalir, 2, 0, 1, 1);


        retranslateUi(modificarProd);

        QMetaObject::connectSlotsByName(modificarProd);
    } // setupUi

    void retranslateUi(QDialog *modificarProd)
    {
        modificarProd->setWindowTitle(QCoreApplication::translate("modificarProd", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("modificarProd", "Qu\303\251 modificaci\303\263n quiere hacer con el producto:", nullptr));
        pbtCambiarCodigo->setText(QCoreApplication::translate("modificarProd", "Cambiar c\303\263digo", nullptr));
        pbtCambiarNombre->setText(QCoreApplication::translate("modificarProd", "Cambiar nombre", nullptr));
        pbtCambiarUnidad->setText(QCoreApplication::translate("modificarProd", "Cambiar unidad", nullptr));
        CambiarPrecio->setText(QCoreApplication::translate("modificarProd", "Cambiar precio", nullptr));
        pbtEliminarProd->setText(QCoreApplication::translate("modificarProd", "Eliminar producto", nullptr));
        pbtSalir->setText(QCoreApplication::translate("modificarProd", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modificarProd: public Ui_modificarProd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARPROD_H
