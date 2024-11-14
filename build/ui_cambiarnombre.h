/********************************************************************************
** Form generated from reading UI file 'cambiarnombre.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMBIARNOMBRE_H
#define UI_CAMBIARNOMBRE_H

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
            cambiarNombre->setObjectName(QStringLiteral("cambiarNombre"));
        cambiarNombre->resize(546, 98);
        gridLayout = new QGridLayout(cambiarNombre);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(cambiarNombre);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letnombre = new QLineEdit(cambiarNombre);
        letnombre->setObjectName(QStringLiteral("letnombre"));
        QFont font1;
        font1.setPointSize(14);
        letnombre->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, letnombre);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(cambiarNombre);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(cambiarNombre);

        QMetaObject::connectSlotsByName(cambiarNombre);
    } // setupUi

    void retranslateUi(QDialog *cambiarNombre)
    {
        cambiarNombre->setWindowTitle(QApplication::translate("cambiarNombre", "Dialog", 0));
        label->setText(QApplication::translate("cambiarNombre", "Ingrese el nuevo nombre:", 0));
    } // retranslateUi

};

namespace Ui {
    class cambiarNombre: public Ui_cambiarNombre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMBIARNOMBRE_H
