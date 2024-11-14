/********************************************************************************
** Form generated from reading UI file 'descuento.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCUENTO_H
#define UI_DESCUENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_descuento
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *letDescuento;
    QLabel *label_2;
    QLineEdit *letTotal;
    QLabel *label_3;
    QLineEdit *letTotalDesc;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *descuento)
    {
        if (descuento->objectName().isEmpty())
            descuento->setObjectName(QStringLiteral("descuento"));
        descuento->resize(423, 290);
        gridLayout = new QGridLayout(descuento);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(descuento);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        letDescuento = new QLineEdit(descuento);
        letDescuento->setObjectName(QStringLiteral("letDescuento"));
        QFont font1;
        font1.setPointSize(16);
        letDescuento->setFont(font1);

        gridLayout->addWidget(letDescuento, 1, 0, 1, 1);

        label_2 = new QLabel(descuento);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        letTotal = new QLineEdit(descuento);
        letTotal->setObjectName(QStringLiteral("letTotal"));
        letTotal->setFont(font1);

        gridLayout->addWidget(letTotal, 3, 0, 1, 1);

        label_3 = new QLabel(descuento);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        letTotalDesc = new QLineEdit(descuento);
        letTotalDesc->setObjectName(QStringLiteral("letTotalDesc"));
        letTotalDesc->setFont(font1);

        gridLayout->addWidget(letTotalDesc, 5, 0, 1, 1);

        buttonBox = new QDialogButtonBox(descuento);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QFont font2;
        font2.setPointSize(14);
        buttonBox->setFont(font2);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 1);


        retranslateUi(descuento);

        QMetaObject::connectSlotsByName(descuento);
    } // setupUi

    void retranslateUi(QDialog *descuento)
    {
        descuento->setWindowTitle(QApplication::translate("descuento", "Dialog", 0));
        label->setText(QApplication::translate("descuento", "Ingrese el monto de descuento:", 0));
        letDescuento->setText(QString());
        label_2->setText(QApplication::translate("descuento", "SubTotal del producto:", 0));
        letTotal->setText(QApplication::translate("descuento", "0", 0));
        label_3->setText(QApplication::translate("descuento", "SubTotal con descuento:", 0));
        letTotalDesc->setText(QApplication::translate("descuento", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class descuento: public Ui_descuento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCUENTO_H
