/********************************************************************************
** Form generated from reading UI file 'cantidad.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANTIDAD_H
#define UI_CANTIDAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_Cantidad
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QLabel *lblCantidad;
    QSpinBox *sbxCantidad;
    QDialogButtonBox *bxAceptar;

    void setupUi(QDialog *Cantidad)
    {
        if (Cantidad->objectName().isEmpty())
            Cantidad->setObjectName("Cantidad");
        Cantidad->resize(259, 157);
        gridLayout = new QGridLayout(Cantidad);
        gridLayout->setObjectName("gridLayout");
        splitter = new QSplitter(Cantidad);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        lblCantidad = new QLabel(splitter);
        lblCantidad->setObjectName("lblCantidad");
        QFont font;
        font.setPointSize(14);
        lblCantidad->setFont(font);
        splitter->addWidget(lblCantidad);
        sbxCantidad = new QSpinBox(splitter);
        sbxCantidad->setObjectName("sbxCantidad");
        QFont font1;
        font1.setPointSize(16);
        sbxCantidad->setFont(font1);
        splitter->addWidget(sbxCantidad);
        bxAceptar = new QDialogButtonBox(splitter);
        bxAceptar->setObjectName("bxAceptar");
        bxAceptar->setFont(font);
        bxAceptar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        splitter->addWidget(bxAceptar);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(Cantidad);

        QMetaObject::connectSlotsByName(Cantidad);
    } // setupUi

    void retranslateUi(QDialog *Cantidad)
    {
        Cantidad->setWindowTitle(QCoreApplication::translate("Cantidad", "Dialog", nullptr));
        lblCantidad->setText(QCoreApplication::translate("Cantidad", "Ingrese la cantidad:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cantidad: public Ui_Cantidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANTIDAD_H
