/********************************************************************************
** Form generated from reading UI file 'agregarnombre.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARNOMBRE_H
#define UI_AGREGARNOMBRE_H

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

class Ui_agregarNombre
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *letNombre;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *agregarNombre)
    {
        if (agregarNombre->objectName().isEmpty())
            agregarNombre->setObjectName("agregarNombre");
        agregarNombre->resize(453, 102);
        gridLayout = new QGridLayout(agregarNombre);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(agregarNombre);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        letNombre = new QLineEdit(agregarNombre);
        letNombre->setObjectName("letNombre");
        QFont font1;
        font1.setPointSize(14);
        letNombre->setFont(font1);

        horizontalLayout->addWidget(letNombre);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(agregarNombre);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(agregarNombre);

        QMetaObject::connectSlotsByName(agregarNombre);
    } // setupUi

    void retranslateUi(QDialog *agregarNombre)
    {
        agregarNombre->setWindowTitle(QCoreApplication::translate("agregarNombre", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("agregarNombre", "Ingrese el nombre:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class agregarNombre: public Ui_agregarNombre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARNOMBRE_H
