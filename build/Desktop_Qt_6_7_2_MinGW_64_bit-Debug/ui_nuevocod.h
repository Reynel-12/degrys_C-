/********************************************************************************
** Form generated from reading UI file 'nuevocod.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOCOD_H
#define UI_NUEVOCOD_H

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

class Ui_nuevoCod
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *letNewCodigo;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *nuevoCod)
    {
        if (nuevoCod->objectName().isEmpty())
            nuevoCod->setObjectName("nuevoCod");
        nuevoCod->resize(581, 102);
        gridLayout = new QGridLayout(nuevoCod);
        gridLayout->setObjectName("gridLayout");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_2 = new QLabel(nuevoCod);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        letNewCodigo = new QLineEdit(nuevoCod);
        letNewCodigo->setObjectName("letNewCodigo");
        QFont font1;
        font1.setPointSize(14);
        letNewCodigo->setFont(font1);
        letNewCodigo->setEchoMode(QLineEdit::Normal);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, letNewCodigo);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(nuevoCod);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(nuevoCod);

        QMetaObject::connectSlotsByName(nuevoCod);
    } // setupUi

    void retranslateUi(QDialog *nuevoCod)
    {
        nuevoCod->setWindowTitle(QCoreApplication::translate("nuevoCod", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("nuevoCod", "Ingrese el nuevo c\303\263digo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nuevoCod: public Ui_nuevoCod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOCOD_H
