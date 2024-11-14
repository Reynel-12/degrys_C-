/********************************************************************************
** Form generated from reading UI file 'cantidad.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANTIDAD_H
#define UI_CANTIDAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            Cantidad->setObjectName(QStringLiteral("Cantidad"));
        Cantidad->resize(259, 157);
        gridLayout = new QGridLayout(Cantidad);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(Cantidad);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        lblCantidad = new QLabel(splitter);
        lblCantidad->setObjectName(QStringLiteral("lblCantidad"));
        QFont font;
        font.setPointSize(14);
        lblCantidad->setFont(font);
        splitter->addWidget(lblCantidad);
        sbxCantidad = new QSpinBox(splitter);
        sbxCantidad->setObjectName(QStringLiteral("sbxCantidad"));
        QFont font1;
        font1.setPointSize(16);
        sbxCantidad->setFont(font1);
        splitter->addWidget(sbxCantidad);
        bxAceptar = new QDialogButtonBox(splitter);
        bxAceptar->setObjectName(QStringLiteral("bxAceptar"));
        bxAceptar->setFont(font);
        bxAceptar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        splitter->addWidget(bxAceptar);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(Cantidad);

        QMetaObject::connectSlotsByName(Cantidad);
    } // setupUi

    void retranslateUi(QDialog *Cantidad)
    {
        Cantidad->setWindowTitle(QApplication::translate("Cantidad", "Dialog", 0));
        lblCantidad->setText(QApplication::translate("Cantidad", "Ingrese la cantidad:", 0));
    } // retranslateUi

};

namespace Ui {
    class Cantidad: public Ui_Cantidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANTIDAD_H
