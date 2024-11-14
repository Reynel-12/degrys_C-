/********************************************************************************
** Form generated from reading UI file 'numinventario.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMINVENTARIO_H
#define UI_NUMINVENTARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_numInventario
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letCantidad;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *numInventario)
    {
        if (numInventario->objectName().isEmpty())
            numInventario->setObjectName("numInventario");
        numInventario->resize(812, 102);
        gridLayout = new QGridLayout(numInventario);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(numInventario);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letCantidad = new QLineEdit(numInventario);
        letCantidad->setObjectName("letCantidad");
        QFont font1;
        font1.setPointSize(14);
        letCantidad->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, letCantidad);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(numInventario);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(numInventario);

        QMetaObject::connectSlotsByName(numInventario);
    } // setupUi

    void retranslateUi(QDialog *numInventario)
    {
        numInventario->setWindowTitle(QCoreApplication::translate("numInventario", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("numInventario", "Ingrese la cantidad que desea agregar al inventario:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class numInventario: public Ui_numInventario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMINVENTARIO_H
