/********************************************************************************
** Form generated from reading UI file 'eliminarproducto.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINARPRODUCTO_H
#define UI_ELIMINARPRODUCTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_eliminarProducto
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *eliminarProducto)
    {
        if (eliminarProducto->objectName().isEmpty())
            eliminarProducto->setObjectName("eliminarProducto");
        eliminarProducto->resize(400, 87);
        gridLayout = new QGridLayout(eliminarProducto);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(eliminarProducto);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(eliminarProducto);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(eliminarProducto);

        QMetaObject::connectSlotsByName(eliminarProducto);
    } // setupUi

    void retranslateUi(QDialog *eliminarProducto)
    {
        eliminarProducto->setWindowTitle(QCoreApplication::translate("eliminarProducto", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("eliminarProducto", "\302\277Est\303\241 seguro en eliminar este producto?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eliminarProducto: public Ui_eliminarProducto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINARPRODUCTO_H
