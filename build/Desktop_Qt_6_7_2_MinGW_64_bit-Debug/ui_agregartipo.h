/********************************************************************************
** Form generated from reading UI file 'agregartipo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARTIPO_H
#define UI_AGREGARTIPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_agregarTipo
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *letUnidad;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *agregarTipo)
    {
        if (agregarTipo->objectName().isEmpty())
            agregarTipo->setObjectName("agregarTipo");
        agregarTipo->resize(496, 102);
        gridLayout = new QGridLayout(agregarTipo);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(agregarTipo);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        letUnidad = new QLineEdit(agregarTipo);
        letUnidad->setObjectName("letUnidad");
        QFont font1;
        font1.setPointSize(14);
        letUnidad->setFont(font1);

        horizontalLayout->addWidget(letUnidad);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(agregarTipo);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(agregarTipo);

        QMetaObject::connectSlotsByName(agregarTipo);
    } // setupUi

    void retranslateUi(QDialog *agregarTipo)
    {
        agregarTipo->setWindowTitle(QCoreApplication::translate("agregarTipo", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("agregarTipo", "Ingrese la unidad:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class agregarTipo: public Ui_agregarTipo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARTIPO_H
