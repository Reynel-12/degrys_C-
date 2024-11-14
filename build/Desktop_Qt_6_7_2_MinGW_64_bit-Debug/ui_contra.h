/********************************************************************************
** Form generated from reading UI file 'contra.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRA_H
#define UI_CONTRA_H

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

class Ui_contra
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letContrasena;
    QDialogButtonBox *btnConfiCancel;

    void setupUi(QDialog *contra)
    {
        if (contra->objectName().isEmpty())
            contra->setObjectName("contra");
        contra->resize(468, 102);
        gridLayout = new QGridLayout(contra);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(contra);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letContrasena = new QLineEdit(contra);
        letContrasena->setObjectName("letContrasena");
        QFont font1;
        font1.setPointSize(14);
        letContrasena->setFont(font1);
        letContrasena->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, letContrasena);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        btnConfiCancel = new QDialogButtonBox(contra);
        btnConfiCancel->setObjectName("btnConfiCancel");
        btnConfiCancel->setFont(font1);
        btnConfiCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnConfiCancel, 1, 0, 1, 1);


        retranslateUi(contra);

        QMetaObject::connectSlotsByName(contra);
    } // setupUi

    void retranslateUi(QDialog *contra)
    {
        contra->setWindowTitle(QCoreApplication::translate("contra", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("contra", "Ingrese la contrase\303\261a:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class contra: public Ui_contra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRA_H
