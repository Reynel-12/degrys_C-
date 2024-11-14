/********************************************************************************
** Form generated from reading UI file 'modificarprod.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARPROD_H
#define UI_MODIFICARPROD_H

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
            modificarProd->setObjectName(QStringLiteral("modificarProd"));
        modificarProd->resize(907, 136);
        gridLayout = new QGridLayout(modificarProd);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(modificarProd);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbtCambiarCodigo = new QPushButton(modificarProd);
        pbtCambiarCodigo->setObjectName(QStringLiteral("pbtCambiarCodigo"));
        QFont font1;
        font1.setPointSize(14);
        pbtCambiarCodigo->setFont(font1);

        horizontalLayout->addWidget(pbtCambiarCodigo);

        pbtCambiarNombre = new QPushButton(modificarProd);
        pbtCambiarNombre->setObjectName(QStringLiteral("pbtCambiarNombre"));
        pbtCambiarNombre->setFont(font1);

        horizontalLayout->addWidget(pbtCambiarNombre);

        pbtCambiarUnidad = new QPushButton(modificarProd);
        pbtCambiarUnidad->setObjectName(QStringLiteral("pbtCambiarUnidad"));
        pbtCambiarUnidad->setFont(font1);

        horizontalLayout->addWidget(pbtCambiarUnidad);

        CambiarPrecio = new QPushButton(modificarProd);
        CambiarPrecio->setObjectName(QStringLiteral("CambiarPrecio"));
        CambiarPrecio->setFont(font1);

        horizontalLayout->addWidget(CambiarPrecio);

        pbtEliminarProd = new QPushButton(modificarProd);
        pbtEliminarProd->setObjectName(QStringLiteral("pbtEliminarProd"));
        pbtEliminarProd->setFont(font1);

        horizontalLayout->addWidget(pbtEliminarProd);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        pbtSalir = new QPushButton(modificarProd);
        pbtSalir->setObjectName(QStringLiteral("pbtSalir"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        pbtSalir->setFont(font2);

        gridLayout->addWidget(pbtSalir, 2, 0, 1, 1);


        retranslateUi(modificarProd);

        QMetaObject::connectSlotsByName(modificarProd);
    } // setupUi

    void retranslateUi(QDialog *modificarProd)
    {
        modificarProd->setWindowTitle(QApplication::translate("modificarProd", "Dialog", 0));
        label->setText(QApplication::translate("modificarProd", "Qu\303\251 modificaci\303\263n quiere hacer con el producto:", 0));
        pbtCambiarCodigo->setText(QApplication::translate("modificarProd", "Cambiar c\303\263digo", 0));
        pbtCambiarNombre->setText(QApplication::translate("modificarProd", "Cambiar nombre", 0));
        pbtCambiarUnidad->setText(QApplication::translate("modificarProd", "Cambiar unidad", 0));
        CambiarPrecio->setText(QApplication::translate("modificarProd", "Cambiar precio", 0));
        pbtEliminarProd->setText(QApplication::translate("modificarProd", "Eliminar producto", 0));
        pbtSalir->setText(QApplication::translate("modificarProd", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class modificarProd: public Ui_modificarProd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARPROD_H
