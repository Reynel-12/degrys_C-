/********************************************************************************
** Form generated from reading UI file 'eliminarproducto.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINARPRODUCTO_H
#define UI_ELIMINARPRODUCTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            eliminarProducto->setObjectName(QStringLiteral("eliminarProducto"));
        eliminarProducto->resize(400, 87);
        gridLayout = new QGridLayout(eliminarProducto);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(eliminarProducto);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(eliminarProducto);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(eliminarProducto);

        QMetaObject::connectSlotsByName(eliminarProducto);
    } // setupUi

    void retranslateUi(QDialog *eliminarProducto)
    {
        eliminarProducto->setWindowTitle(QApplication::translate("eliminarProducto", "Dialog", 0));
        label->setText(QApplication::translate("eliminarProducto", "\302\277Est\303\241 seguro en eliminar este producto?", 0));
    } // retranslateUi

};

namespace Ui {
    class eliminarProducto: public Ui_eliminarProducto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINARPRODUCTO_H
