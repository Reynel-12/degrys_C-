/********************************************************************************
** Form generated from reading UI file 'agregarinventario.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARINVENTARIO_H
#define UI_AGREGARINVENTARIO_H

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

class Ui_agregarInventario
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letCodigo;
    QDialogButtonBox *btnConfiCancel;

    void setupUi(QDialog *agregarInventario)
    {
        if (agregarInventario->objectName().isEmpty())
            agregarInventario->setObjectName(QStringLiteral("agregarInventario"));
        agregarInventario->resize(520, 101);
        gridLayout = new QGridLayout(agregarInventario);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(agregarInventario);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letCodigo = new QLineEdit(agregarInventario);
        letCodigo->setObjectName(QStringLiteral("letCodigo"));
        QFont font1;
        font1.setPointSize(14);
        letCodigo->setFont(font1);
        letCodigo->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(0, QFormLayout::FieldRole, letCodigo);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        btnConfiCancel = new QDialogButtonBox(agregarInventario);
        btnConfiCancel->setObjectName(QStringLiteral("btnConfiCancel"));
        btnConfiCancel->setFont(font1);
        btnConfiCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnConfiCancel, 1, 0, 1, 1);


        retranslateUi(agregarInventario);

        QMetaObject::connectSlotsByName(agregarInventario);
    } // setupUi

    void retranslateUi(QDialog *agregarInventario)
    {
        agregarInventario->setWindowTitle(QApplication::translate("agregarInventario", "Dialog", 0));
        label->setText(QApplication::translate("agregarInventario", "Ingrese el c\303\263digo del producto:", 0));
    } // retranslateUi

};

namespace Ui {
    class agregarInventario: public Ui_agregarInventario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARINVENTARIO_H
