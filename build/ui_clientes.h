/********************************************************************************
** Form generated from reading UI file 'clientes.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTES_H
#define UI_CLIENTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_clientes
{
public:
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *letProducto;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLineEdit *letUnidad;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLineEdit *letCantidad;
    QGridLayout *gridLayout_5;
    QLabel *label_6;
    QLineEdit *letSubTotal;
    QGridLayout *gridLayout_6;
    QLabel *label_7;
    QLineEdit *letFecha;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QTableView *tvwClientes;
    QTableView *tvwProductos;
    QTableView *tvwPagos;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbtConfirmar;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *letTotal;
    QPushButton *pbtCancelMonto;

    void setupUi(QDialog *clientes)
    {
        if (clientes->objectName().isEmpty())
            clientes->setObjectName(QStringLiteral("clientes"));
        clientes->resize(1310, 665);
        gridLayout_8 = new QGridLayout(clientes);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(clientes);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        letProducto = new QLineEdit(clientes);
        letProducto->setObjectName(QStringLiteral("letProducto"));
        letProducto->setFont(font);

        gridLayout_2->addWidget(letProducto, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_5 = new QLabel(clientes);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        letUnidad = new QLineEdit(clientes);
        letUnidad->setObjectName(QStringLiteral("letUnidad"));
        letUnidad->setFont(font);

        gridLayout_4->addWidget(letUnidad, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(clientes);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        letCantidad = new QLineEdit(clientes);
        letCantidad->setObjectName(QStringLiteral("letCantidad"));
        letCantidad->setFont(font);

        gridLayout_3->addWidget(letCantidad, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 2, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_6 = new QLabel(clientes);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        letSubTotal = new QLineEdit(clientes);
        letSubTotal->setObjectName(QStringLiteral("letSubTotal"));
        letSubTotal->setFont(font);

        gridLayout_5->addWidget(letSubTotal, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 0, 3, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_7 = new QLabel(clientes);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        letFecha = new QLineEdit(clientes);
        letFecha->setObjectName(QStringLiteral("letFecha"));
        letFecha->setFont(font);

        gridLayout_6->addWidget(letFecha, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 4, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(clientes);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);


        gridLayout_8->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tvwClientes = new QTableView(clientes);
        tvwClientes->setObjectName(QStringLiteral("tvwClientes"));
        tvwClientes->setFont(font);

        gridLayout->addWidget(tvwClientes, 0, 0, 1, 1);

        tvwProductos = new QTableView(clientes);
        tvwProductos->setObjectName(QStringLiteral("tvwProductos"));
        tvwProductos->setFont(font);

        gridLayout->addWidget(tvwProductos, 0, 1, 1, 1);

        tvwPagos = new QTableView(clientes);
        tvwPagos->setObjectName(QStringLiteral("tvwPagos"));
        tvwPagos->setFont(font);

        gridLayout->addWidget(tvwPagos, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbtConfirmar = new QPushButton(clientes);
        pbtConfirmar->setObjectName(QStringLiteral("pbtConfirmar"));
        pbtConfirmar->setFont(font);

        horizontalLayout->addWidget(pbtConfirmar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(clientes);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        letTotal = new QLineEdit(clientes);
        letTotal->setObjectName(QStringLiteral("letTotal"));
        letTotal->setFont(font);

        horizontalLayout_2->addWidget(letTotal);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        pbtCancelMonto = new QPushButton(clientes);
        pbtCancelMonto->setObjectName(QStringLiteral("pbtCancelMonto"));
        pbtCancelMonto->setFont(font);

        horizontalLayout_3->addWidget(pbtCancelMonto);


        horizontalLayout->addLayout(horizontalLayout_3);


        gridLayout_8->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(clientes);
        QObject::connect(pbtConfirmar, SIGNAL(clicked()), clientes, SLOT(Confirmar()));
        QObject::connect(pbtCancelMonto, SIGNAL(clicked()), clientes, SLOT(CancelarMonto()));

        QMetaObject::connectSlotsByName(clientes);
    } // setupUi

    void retranslateUi(QDialog *clientes)
    {
        clientes->setWindowTitle(QApplication::translate("clientes", "Dialog", 0));
        label_3->setText(QApplication::translate("clientes", "Producto", 0));
        label_5->setText(QApplication::translate("clientes", "Unidad", 0));
        label_4->setText(QApplication::translate("clientes", "Cantidad", 0));
        label_6->setText(QApplication::translate("clientes", "SubTotal", 0));
        label_7->setText(QApplication::translate("clientes", "Fecha", 0));
        label_2->setText(QApplication::translate("clientes", "Seleccione el cliente", 0));
        pbtConfirmar->setText(QApplication::translate("clientes", "Ver productos", 0));
        label->setText(QApplication::translate("clientes", "Total:", 0));
        letTotal->setText(QApplication::translate("clientes", "0", 0));
        pbtCancelMonto->setText(QApplication::translate("clientes", "Cancelar Monto", 0));
    } // retranslateUi

};

namespace Ui {
    class clientes: public Ui_clientes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTES_H
