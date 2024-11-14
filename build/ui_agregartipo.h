/********************************************************************************
** Form generated from reading UI file 'agregartipo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARTIPO_H
#define UI_AGREGARTIPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            agregarTipo->setObjectName(QStringLiteral("agregarTipo"));
        agregarTipo->resize(496, 102);
        gridLayout = new QGridLayout(agregarTipo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(agregarTipo);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        letUnidad = new QLineEdit(agregarTipo);
        letUnidad->setObjectName(QStringLiteral("letUnidad"));
        QFont font1;
        font1.setPointSize(14);
        letUnidad->setFont(font1);

        horizontalLayout->addWidget(letUnidad);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(agregarTipo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(agregarTipo);

        QMetaObject::connectSlotsByName(agregarTipo);
    } // setupUi

    void retranslateUi(QDialog *agregarTipo)
    {
        agregarTipo->setWindowTitle(QApplication::translate("agregarTipo", "Dialog", 0));
        label->setText(QApplication::translate("agregarTipo", "Ingrese la unidad:", 0));
    } // retranslateUi

};

namespace Ui {
    class agregarTipo: public Ui_agregarTipo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARTIPO_H
