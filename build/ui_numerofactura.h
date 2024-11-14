/********************************************************************************
** Form generated from reading UI file 'numerofactura.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMEROFACTURA_H
#define UI_NUMEROFACTURA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_numeroFactura
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spbNumFac;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *numeroFactura)
    {
        if (numeroFactura->objectName().isEmpty())
            numeroFactura->setObjectName(QStringLiteral("numeroFactura"));
        numeroFactura->resize(340, 133);
        gridLayout = new QGridLayout(numeroFactura);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(numeroFactura);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        spbNumFac = new QSpinBox(numeroFactura);
        spbNumFac->setObjectName(QStringLiteral("spbNumFac"));
        QFont font1;
        font1.setPointSize(14);
        spbNumFac->setFont(font1);
        spbNumFac->setMinimum(1);
        spbNumFac->setMaximum(9999);

        verticalLayout->addWidget(spbNumFac);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(numeroFactura);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(numeroFactura);

        QMetaObject::connectSlotsByName(numeroFactura);
    } // setupUi

    void retranslateUi(QDialog *numeroFactura)
    {
        numeroFactura->setWindowTitle(QApplication::translate("numeroFactura", "Dialog", 0));
        label->setText(QApplication::translate("numeroFactura", "Ingrese el n\303\272mero de factura:", 0));
    } // retranslateUi

};

namespace Ui {
    class numeroFactura: public Ui_numeroFactura {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMEROFACTURA_H
