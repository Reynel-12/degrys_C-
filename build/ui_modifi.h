/********************************************************************************
** Form generated from reading UI file 'modifi.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFI_H
#define UI_MODIFI_H

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

class Ui_modifi
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letCodigo;
    QDialogButtonBox *btnConfiCancel;

    void setupUi(QDialog *modifi)
    {
        if (modifi->objectName().isEmpty())
            modifi->setObjectName(QStringLiteral("modifi"));
        modifi->resize(815, 103);
        gridLayout = new QGridLayout(modifi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(modifi);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letCodigo = new QLineEdit(modifi);
        letCodigo->setObjectName(QStringLiteral("letCodigo"));
        QFont font1;
        font1.setPointSize(14);
        letCodigo->setFont(font1);
        letCodigo->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(0, QFormLayout::FieldRole, letCodigo);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        btnConfiCancel = new QDialogButtonBox(modifi);
        btnConfiCancel->setObjectName(QStringLiteral("btnConfiCancel"));
        btnConfiCancel->setFont(font1);
        btnConfiCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(btnConfiCancel, 1, 0, 1, 1);


        retranslateUi(modifi);

        QMetaObject::connectSlotsByName(modifi);
    } // setupUi

    void retranslateUi(QDialog *modifi)
    {
        modifi->setWindowTitle(QApplication::translate("modifi", "Dialog", 0));
        label->setText(QApplication::translate("modifi", "Ingrese el c\303\263digo del producto al que desea modificar:", 0));
    } // retranslateUi

};

namespace Ui {
    class modifi: public Ui_modifi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFI_H
