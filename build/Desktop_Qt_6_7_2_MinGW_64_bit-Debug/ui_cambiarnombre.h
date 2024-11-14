/********************************************************************************
** Form generated from reading UI file 'cambiarnombre.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIARNOMBRE_H
#define UI_CAMBIARNOMBRE_H

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

class Ui_cambiarNombre
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letnombre;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *cambiarNombre)
    {
        if (cambiarNombre->objectName().isEmpty())
            cambiarNombre->setObjectName("cambiarNombre");
        cambiarNombre->resize(546, 98);
        gridLayout = new QGridLayout(cambiarNombre);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(cambiarNombre);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letnombre = new QLineEdit(cambiarNombre);
        letnombre->setObjectName("letnombre");
        QFont font1;
        font1.setPointSize(14);
        letnombre->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, letnombre);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(cambiarNombre);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(cambiarNombre);

        QMetaObject::connectSlotsByName(cambiarNombre);
    } // setupUi

    void retranslateUi(QDialog *cambiarNombre)
    {
        cambiarNombre->setWindowTitle(QCoreApplication::translate("cambiarNombre", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("cambiarNombre", "Ingrese el nuevo nombre:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cambiarNombre: public Ui_cambiarNombre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIARNOMBRE_H
