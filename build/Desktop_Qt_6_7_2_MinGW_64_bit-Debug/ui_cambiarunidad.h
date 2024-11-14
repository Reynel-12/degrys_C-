/********************************************************************************
** Form generated from reading UI file 'cambiarunidad.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIARUNIDAD_H
#define UI_CAMBIARUNIDAD_H

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

class Ui_cambiarUnidad
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letUnidad;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *cambiarUnidad)
    {
        if (cambiarUnidad->objectName().isEmpty())
            cambiarUnidad->setObjectName("cambiarUnidad");
        cambiarUnidad->resize(594, 103);
        gridLayout = new QGridLayout(cambiarUnidad);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(cambiarUnidad);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letUnidad = new QLineEdit(cambiarUnidad);
        letUnidad->setObjectName("letUnidad");
        QFont font1;
        font1.setPointSize(14);
        letUnidad->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, letUnidad);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(cambiarUnidad);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(cambiarUnidad);

        QMetaObject::connectSlotsByName(cambiarUnidad);
    } // setupUi

    void retranslateUi(QDialog *cambiarUnidad)
    {
        cambiarUnidad->setWindowTitle(QCoreApplication::translate("cambiarUnidad", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("cambiarUnidad", "Ingrese el nombre de la unidad:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cambiarUnidad: public Ui_cambiarUnidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIARUNIDAD_H
