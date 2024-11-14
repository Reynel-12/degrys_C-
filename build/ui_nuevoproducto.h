/********************************************************************************
** Form generated from reading UI file 'nuevoproducto.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOPRODUCTO_H
#define UI_NUEVOPRODUCTO_H

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

class Ui_nuevoProducto
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *letCodigo;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *letNombre;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QLineEdit *letUnidad;
    QFormLayout *formLayout_4;
    QLabel *label_5;
    QLineEdit *letInventario;
    QFormLayout *formLayout_5;
    QLabel *label_4;
    QLineEdit *letPrecio;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *nuevoProducto)
    {
        if (nuevoProducto->objectName().isEmpty())
            nuevoProducto->setObjectName(QStringLiteral("nuevoProducto"));
        nuevoProducto->resize(486, 274);
        gridLayout = new QGridLayout(nuevoProducto);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(nuevoProducto);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        letCodigo = new QLineEdit(nuevoProducto);
        letCodigo->setObjectName(QStringLiteral("letCodigo"));
        QFont font1;
        font1.setPointSize(14);
        letCodigo->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, letCodigo);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(nuevoProducto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        letNombre = new QLineEdit(nuevoProducto);
        letNombre->setObjectName(QStringLiteral("letNombre"));
        letNombre->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, letNombre);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_3 = new QLabel(nuevoProducto);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        letUnidad = new QLineEdit(nuevoProducto);
        letUnidad->setObjectName(QStringLiteral("letUnidad"));
        letUnidad->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, letUnidad);


        gridLayout->addLayout(formLayout_3, 2, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_5 = new QLabel(nuevoProducto);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_5);

        letInventario = new QLineEdit(nuevoProducto);
        letInventario->setObjectName(QStringLiteral("letInventario"));
        letInventario->setFont(font1);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, letInventario);


        gridLayout->addLayout(formLayout_4, 3, 0, 1, 1);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        label_4 = new QLabel(nuevoProducto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_4);

        letPrecio = new QLineEdit(nuevoProducto);
        letPrecio->setObjectName(QStringLiteral("letPrecio"));
        letPrecio->setFont(font1);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, letPrecio);


        gridLayout->addLayout(formLayout_5, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(nuevoProducto);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 1);


        retranslateUi(nuevoProducto);

        QMetaObject::connectSlotsByName(nuevoProducto);
    } // setupUi

    void retranslateUi(QDialog *nuevoProducto)
    {
        nuevoProducto->setWindowTitle(QApplication::translate("nuevoProducto", "Dialog", 0));
        label->setText(QApplication::translate("nuevoProducto", "C\303\263digo:", 0));
        label_2->setText(QApplication::translate("nuevoProducto", "Nombre:", 0));
        letNombre->setText(QString());
        label_3->setText(QApplication::translate("nuevoProducto", "Unidad:", 0));
        label_5->setText(QApplication::translate("nuevoProducto", "Inventario:", 0));
        label_4->setText(QApplication::translate("nuevoProducto", "Precio:", 0));
    } // retranslateUi

};

namespace Ui {
    class nuevoProducto: public Ui_nuevoProducto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOPRODUCTO_H
