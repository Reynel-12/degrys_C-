/********************************************************************************
** Form generated from reading UI file 'cambiarprecio.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIARPRECIO_H
#define UI_CAMBIARPRECIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_cambiarPrecio
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letPrecio;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *cambiarPrecio)
    {
        if (cambiarPrecio->objectName().isEmpty())
            cambiarPrecio->setObjectName(QStringLiteral("cambiarPrecio"));
        cambiarPrecio->resize(636, 105);
        gridLayout = new QGridLayout(cambiarPrecio);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(cambiarPrecio);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letPrecio = new QLineEdit(cambiarPrecio);
        letPrecio->setObjectName(QStringLiteral("letPrecio"));
        QFont font1;
        font1.setPointSize(14);
        letPrecio->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, letPrecio);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(cambiarPrecio);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(cambiarPrecio);

        QMetaObject::connectSlotsByName(cambiarPrecio);
    } // setupUi

    void retranslateUi(QDialog *cambiarPrecio)
    {
        cambiarPrecio->setWindowTitle(QApplication::translate("cambiarPrecio", "Dialog", 0));
        label->setText(QApplication::translate("cambiarPrecio", "Ingrese el nuevo precio del producto:", 0));
        letPrecio->setText(QApplication::translate("cambiarPrecio", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class cambiarPrecio: public Ui_cambiarPrecio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIARPRECIO_H
