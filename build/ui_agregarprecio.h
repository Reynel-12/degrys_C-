/********************************************************************************
** Form generated from reading UI file 'agregarprecio.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREGARPRECIO_H
#define UI_AGREGARPRECIO_H

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

class Ui_agregarPrecio
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *letPrecio;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *agregarPrecio)
    {
        if (agregarPrecio->objectName().isEmpty())
            agregarPrecio->setObjectName(QStringLiteral("agregarPrecio"));
        agregarPrecio->resize(414, 102);
        gridLayout = new QGridLayout(agregarPrecio);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(agregarPrecio);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        letPrecio = new QLineEdit(agregarPrecio);
        letPrecio->setObjectName(QStringLiteral("letPrecio"));
        QFont font1;
        font1.setPointSize(14);
        letPrecio->setFont(font1);

        horizontalLayout->addWidget(letPrecio);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(agregarPrecio);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(agregarPrecio);

        QMetaObject::connectSlotsByName(agregarPrecio);
    } // setupUi

    void retranslateUi(QDialog *agregarPrecio)
    {
        agregarPrecio->setWindowTitle(QApplication::translate("agregarPrecio", "Dialog", 0));
        label->setText(QApplication::translate("agregarPrecio", "Ingrese el precio:", 0));
        letPrecio->setText(QApplication::translate("agregarPrecio", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class agregarPrecio: public Ui_agregarPrecio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREGARPRECIO_H
