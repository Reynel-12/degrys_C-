/********************************************************************************
** Form generated from reading UI file 'clientes.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTES_H
#define UI_CLIENTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
            clientes->setObjectName("clientes");
        clientes->resize(1310, 665);
        gridLayout_8 = new QGridLayout(clientes);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_3 = new QLabel(clientes);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        letProducto = new QLineEdit(clientes);
        letProducto->setObjectName("letProducto");
        letProducto->setFont(font);

        gridLayout_2->addWidget(letProducto, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_5 = new QLabel(clientes);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        letUnidad = new QLineEdit(clientes);
        letUnidad->setObjectName("letUnidad");
        letUnidad->setFont(font);

        gridLayout_4->addWidget(letUnidad, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label_4 = new QLabel(clientes);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        letCantidad = new QLineEdit(clientes);
        letCantidad->setObjectName("letCantidad");
        letCantidad->setFont(font);

        gridLayout_3->addWidget(letCantidad, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 2, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_6 = new QLabel(clientes);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        letSubTotal = new QLineEdit(clientes);
        letSubTotal->setObjectName("letSubTotal");
        letSubTotal->setFont(font);

        gridLayout_5->addWidget(letSubTotal, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 0, 3, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        label_7 = new QLabel(clientes);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        letFecha = new QLineEdit(clientes);
        letFecha->setObjectName("letFecha");
        letFecha->setFont(font);

        gridLayout_6->addWidget(letFecha, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 4, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(clientes);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);


        gridLayout_8->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        tvwClientes = new QTableView(clientes);
        tvwClientes->setObjectName("tvwClientes");
        tvwClientes->setFont(font);

        gridLayout->addWidget(tvwClientes, 0, 0, 1, 1);

        tvwProductos = new QTableView(clientes);
        tvwProductos->setObjectName("tvwProductos");
        tvwProductos->setFont(font);

        gridLayout->addWidget(tvwProductos, 0, 1, 1, 1);

        tvwPagos = new QTableView(clientes);
        tvwPagos->setObjectName("tvwPagos");
        tvwPagos->setFont(font);

        gridLayout->addWidget(tvwPagos, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbtConfirmar = new QPushButton(clientes);
        pbtConfirmar->setObjectName("pbtConfirmar");
        pbtConfirmar->setFont(font);

        horizontalLayout->addWidget(pbtConfirmar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(clientes);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        letTotal = new QLineEdit(clientes);
        letTotal->setObjectName("letTotal");
        letTotal->setFont(font);

        horizontalLayout_2->addWidget(letTotal);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        pbtCancelMonto = new QPushButton(clientes);
        pbtCancelMonto->setObjectName("pbtCancelMonto");
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
        clientes->setWindowTitle(QCoreApplication::translate("clientes", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("clientes", "Producto", nullptr));
        label_5->setText(QCoreApplication::translate("clientes", "Unidad", nullptr));
        label_4->setText(QCoreApplication::translate("clientes", "Cantidad", nullptr));
        label_6->setText(QCoreApplication::translate("clientes", "SubTotal", nullptr));
        label_7->setText(QCoreApplication::translate("clientes", "Fecha", nullptr));
        label_2->setText(QCoreApplication::translate("clientes", "Seleccione el cliente", nullptr));
        pbtConfirmar->setText(QCoreApplication::translate("clientes", "Ver productos", nullptr));
        label->setText(QCoreApplication::translate("clientes", "Total:", nullptr));
        letTotal->setText(QCoreApplication::translate("clientes", "0", nullptr));
        pbtCancelMonto->setText(QCoreApplication::translate("clientes", "Cancelar Monto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientes: public Ui_clientes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTES_H
