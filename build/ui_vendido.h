/********************************************************************************
** Form generated from reading UI file 'vendido.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENDIDO_H
#define UI_VENDIDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Vendido
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *letNoFac;
    QPushButton *pbtNoFac;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QComboBox *cbxFiltros;
    QPushButton *pbtGrafico;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_13;
    QLineEdit *letFactura;
    QLineEdit *letProducto;
    QLineEdit *letTipo;
    QLineEdit *letCantidad;
    QLineEdit *letSubtotal;
    QLineEdit *letTotalFac;
    QLineEdit *letCliente;
    QLineEdit *letCambio;
    QLineEdit *letFecha;
    QLineEdit *letHora;
    QLineEdit *letDescuento;
    QLineEdit *letCaja;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *letTotal;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QLineEdit *letTotal_2;
    QGridLayout *gridLayout_2;
    QPushButton *pbtGenerarReporte;
    QPushButton *pbtCargar;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *twtVendido;
    QTableWidget *twtFac;

    void setupUi(QDialog *Vendido)
    {
        if (Vendido->objectName().isEmpty())
            Vendido->setObjectName(QStringLiteral("Vendido"));
        Vendido->resize(1628, 584);
        gridLayout_3 = new QGridLayout(Vendido);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Vendido);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        letNoFac = new QLineEdit(Vendido);
        letNoFac->setObjectName(QStringLiteral("letNoFac"));
        QFont font1;
        font1.setPointSize(12);
        letNoFac->setFont(font1);

        gridLayout->addWidget(letNoFac, 0, 1, 1, 1);

        pbtNoFac = new QPushButton(Vendido);
        pbtNoFac->setObjectName(QStringLiteral("pbtNoFac"));
        QFont font2;
        font2.setPointSize(14);
        pbtNoFac->setFont(font2);

        gridLayout->addWidget(pbtNoFac, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_15 = new QLabel(Vendido);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        horizontalLayout_4->addWidget(label_15);

        cbxFiltros = new QComboBox(Vendido);
        cbxFiltros->setObjectName(QStringLiteral("cbxFiltros"));
        cbxFiltros->setFont(font1);

        horizontalLayout_4->addWidget(cbxFiltros);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 4, 1, 3);

        pbtGrafico = new QPushButton(Vendido);
        pbtGrafico->setObjectName(QStringLiteral("pbtGrafico"));
        pbtGrafico->setFont(font1);

        gridLayout_3->addWidget(pbtGrafico, 0, 7, 1, 1);

        label_2 = new QLabel(Vendido);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(Vendido);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout_3->addWidget(label_3, 1, 1, 1, 1);

        label_4 = new QLabel(Vendido);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_3->addWidget(label_4, 1, 2, 1, 1);

        label_5 = new QLabel(Vendido);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout_3->addWidget(label_5, 1, 3, 1, 1);

        label_7 = new QLabel(Vendido);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        gridLayout_3->addWidget(label_7, 1, 4, 1, 1);

        label_8 = new QLabel(Vendido);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        gridLayout_3->addWidget(label_8, 1, 5, 1, 1);

        label_9 = new QLabel(Vendido);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 1, 6, 1, 1);

        label_10 = new QLabel(Vendido);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        gridLayout_3->addWidget(label_10, 1, 7, 1, 1);

        label_11 = new QLabel(Vendido);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        gridLayout_3->addWidget(label_11, 1, 8, 1, 1);

        label_12 = new QLabel(Vendido);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        gridLayout_3->addWidget(label_12, 1, 9, 1, 1);

        label_16 = new QLabel(Vendido);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        gridLayout_3->addWidget(label_16, 1, 10, 1, 1);

        label_13 = new QLabel(Vendido);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        gridLayout_3->addWidget(label_13, 1, 11, 1, 1);

        letFactura = new QLineEdit(Vendido);
        letFactura->setObjectName(QStringLiteral("letFactura"));
        letFactura->setFont(font1);

        gridLayout_3->addWidget(letFactura, 2, 0, 1, 1);

        letProducto = new QLineEdit(Vendido);
        letProducto->setObjectName(QStringLiteral("letProducto"));
        letProducto->setFont(font1);

        gridLayout_3->addWidget(letProducto, 2, 1, 1, 1);

        letTipo = new QLineEdit(Vendido);
        letTipo->setObjectName(QStringLiteral("letTipo"));
        letTipo->setFont(font1);

        gridLayout_3->addWidget(letTipo, 2, 2, 1, 1);

        letCantidad = new QLineEdit(Vendido);
        letCantidad->setObjectName(QStringLiteral("letCantidad"));
        letCantidad->setFont(font1);

        gridLayout_3->addWidget(letCantidad, 2, 3, 1, 1);

        letSubtotal = new QLineEdit(Vendido);
        letSubtotal->setObjectName(QStringLiteral("letSubtotal"));
        letSubtotal->setFont(font1);

        gridLayout_3->addWidget(letSubtotal, 2, 4, 1, 1);

        letTotalFac = new QLineEdit(Vendido);
        letTotalFac->setObjectName(QStringLiteral("letTotalFac"));
        letTotalFac->setFont(font1);

        gridLayout_3->addWidget(letTotalFac, 2, 5, 1, 1);

        letCliente = new QLineEdit(Vendido);
        letCliente->setObjectName(QStringLiteral("letCliente"));
        letCliente->setFont(font1);

        gridLayout_3->addWidget(letCliente, 2, 6, 1, 1);

        letCambio = new QLineEdit(Vendido);
        letCambio->setObjectName(QStringLiteral("letCambio"));
        letCambio->setFont(font1);

        gridLayout_3->addWidget(letCambio, 2, 7, 1, 1);

        letFecha = new QLineEdit(Vendido);
        letFecha->setObjectName(QStringLiteral("letFecha"));
        letFecha->setFont(font1);

        gridLayout_3->addWidget(letFecha, 2, 8, 1, 1);

        letHora = new QLineEdit(Vendido);
        letHora->setObjectName(QStringLiteral("letHora"));
        letHora->setFont(font1);

        gridLayout_3->addWidget(letHora, 2, 9, 1, 1);

        letDescuento = new QLineEdit(Vendido);
        letDescuento->setObjectName(QStringLiteral("letDescuento"));
        letDescuento->setFont(font1);

        gridLayout_3->addWidget(letDescuento, 2, 10, 1, 1);

        letCaja = new QLineEdit(Vendido);
        letCaja->setObjectName(QStringLiteral("letCaja"));
        letCaja->setFont(font1);

        gridLayout_3->addWidget(letCaja, 2, 11, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(Vendido);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        horizontalLayout->addWidget(label_6);

        letTotal = new QLineEdit(Vendido);
        letTotal->setObjectName(QStringLiteral("letTotal"));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        letTotal->setFont(font3);
        letTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(letTotal);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout, 4, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_14 = new QLabel(Vendido);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font2);

        horizontalLayout_3->addWidget(label_14);

        letTotal_2 = new QLineEdit(Vendido);
        letTotal_2->setObjectName(QStringLiteral("letTotal_2"));
        letTotal_2->setFont(font3);
        letTotal_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(letTotal_2);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 8, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pbtGenerarReporte = new QPushButton(Vendido);
        pbtGenerarReporte->setObjectName(QStringLiteral("pbtGenerarReporte"));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setWeight(50);
        pbtGenerarReporte->setFont(font4);

        gridLayout_2->addWidget(pbtGenerarReporte, 0, 0, 1, 1);

        pbtCargar = new QPushButton(Vendido);
        pbtCargar->setObjectName(QStringLiteral("pbtCargar"));
        pbtCargar->setFont(font4);

        gridLayout_2->addWidget(pbtCargar, 0, 1, 1, 1);

        pushButton = new QPushButton(Vendido);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font4);

        gridLayout_2->addWidget(pushButton, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 5, 8, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        twtVendido = new QTableWidget(Vendido);
        if (twtVendido->columnCount() < 12)
            twtVendido->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        twtVendido->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        twtVendido->setObjectName(QStringLiteral("twtVendido"));
        twtVendido->setFont(font1);

        horizontalLayout_2->addWidget(twtVendido);

        twtFac = new QTableWidget(Vendido);
        if (twtFac->columnCount() < 12)
            twtFac->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(6, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(7, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(8, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(9, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(10, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        twtFac->setHorizontalHeaderItem(11, __qtablewidgetitem23);
        twtFac->setObjectName(QStringLiteral("twtFac"));
        twtFac->setFont(font1);

        horizontalLayout_2->addWidget(twtFac);


        gridLayout_3->addLayout(horizontalLayout_2, 3, 0, 1, 12);


        retranslateUi(Vendido);
        QObject::connect(pbtNoFac, SIGNAL(clicked()), Vendido, SLOT(BuscarFac()));
        QObject::connect(pbtCargar, SIGNAL(clicked()), Vendido, SLOT(AbrirHistorial()));
        QObject::connect(twtVendido, SIGNAL(itemClicked(QTableWidgetItem*)), Vendido, SLOT(SeleccionProd()));
        QObject::connect(twtFac, SIGNAL(itemClicked(QTableWidgetItem*)), Vendido, SLOT(SeleccionProdFac()));
        QObject::connect(pbtGenerarReporte, SIGNAL(clicked()), Vendido, SLOT(GenerarReporte()));

        QMetaObject::connectSlotsByName(Vendido);
    } // setupUi

    void retranslateUi(QDialog *Vendido)
    {
        Vendido->setWindowTitle(QApplication::translate("Vendido", "Dialog", 0));
        label->setText(QApplication::translate("Vendido", "Factura N#", 0));
        letNoFac->setText(QString());
        pbtNoFac->setText(QApplication::translate("Vendido", "Buscar", 0));
        label_15->setText(QApplication::translate("Vendido", "Filtros de busqueda", 0));
        cbxFiltros->clear();
        cbxFiltros->insertItems(0, QStringList()
         << QApplication::translate("Vendido", "Todas las cajas", 0)
         << QApplication::translate("Vendido", "Caja principal", 0)
         << QApplication::translate("Vendido", "Caja 1", 0)
         << QApplication::translate("Vendido", "Caja 2", 0)
        );
        pbtGrafico->setText(QApplication::translate("Vendido", "Gr\303\241fico", 0));
        label_2->setText(QApplication::translate("Vendido", "Factura", 0));
        label_3->setText(QApplication::translate("Vendido", "Producto", 0));
        label_4->setText(QApplication::translate("Vendido", "Tipo", 0));
        label_5->setText(QApplication::translate("Vendido", "Cantidad", 0));
        label_7->setText(QApplication::translate("Vendido", "SubTotal", 0));
        label_8->setText(QApplication::translate("Vendido", "Total", 0));
        label_9->setText(QApplication::translate("Vendido", "Cliente", 0));
        label_10->setText(QApplication::translate("Vendido", "Cambio", 0));
        label_11->setText(QApplication::translate("Vendido", "Fecha", 0));
        label_12->setText(QApplication::translate("Vendido", "Hora", 0));
        label_16->setText(QApplication::translate("Vendido", "Descuento", 0));
        label_13->setText(QApplication::translate("Vendido", "Caja", 0));
        letDescuento->setText(QString());
        label_6->setText(QApplication::translate("Vendido", "Total", 0));
        letTotal->setText(QApplication::translate("Vendido", "0", 0));
        label_14->setText(QApplication::translate("Vendido", "Total", 0));
        letTotal_2->setText(QApplication::translate("Vendido", "0", 0));
        pbtGenerarReporte->setText(QApplication::translate("Vendido", "Generar reporte", 0));
        pbtCargar->setText(QApplication::translate("Vendido", "Cargar", 0));
        pushButton->setText(QApplication::translate("Vendido", "Salir", 0));
        QTableWidgetItem *___qtablewidgetitem = twtVendido->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Vendido", "Factura", 0));
        QTableWidgetItem *___qtablewidgetitem1 = twtVendido->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Vendido", "Producto", 0));
        QTableWidgetItem *___qtablewidgetitem2 = twtVendido->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Vendido", "Tipo", 0));
        QTableWidgetItem *___qtablewidgetitem3 = twtVendido->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Vendido", "Cantidad", 0));
        QTableWidgetItem *___qtablewidgetitem4 = twtVendido->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Vendido", "SubTotal", 0));
        QTableWidgetItem *___qtablewidgetitem5 = twtVendido->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Vendido", "Total", 0));
        QTableWidgetItem *___qtablewidgetitem6 = twtVendido->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Vendido", "Cliente", 0));
        QTableWidgetItem *___qtablewidgetitem7 = twtVendido->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Vendido", "Cambio", 0));
        QTableWidgetItem *___qtablewidgetitem8 = twtVendido->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Vendido", "Fecha", 0));
        QTableWidgetItem *___qtablewidgetitem9 = twtVendido->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Vendido", "Hora", 0));
        QTableWidgetItem *___qtablewidgetitem10 = twtVendido->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Vendido", "Descuento", 0));
        QTableWidgetItem *___qtablewidgetitem11 = twtVendido->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("Vendido", "Caja", 0));
        QTableWidgetItem *___qtablewidgetitem12 = twtFac->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("Vendido", "Factura", 0));
        QTableWidgetItem *___qtablewidgetitem13 = twtFac->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("Vendido", "Productos", 0));
        QTableWidgetItem *___qtablewidgetitem14 = twtFac->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("Vendido", "Tipo", 0));
        QTableWidgetItem *___qtablewidgetitem15 = twtFac->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("Vendido", "Cantidad", 0));
        QTableWidgetItem *___qtablewidgetitem16 = twtFac->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("Vendido", "SubTotal", 0));
        QTableWidgetItem *___qtablewidgetitem17 = twtFac->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QApplication::translate("Vendido", "Total", 0));
        QTableWidgetItem *___qtablewidgetitem18 = twtFac->horizontalHeaderItem(6);
        ___qtablewidgetitem18->setText(QApplication::translate("Vendido", "Cliente", 0));
        QTableWidgetItem *___qtablewidgetitem19 = twtFac->horizontalHeaderItem(7);
        ___qtablewidgetitem19->setText(QApplication::translate("Vendido", "Cambio", 0));
        QTableWidgetItem *___qtablewidgetitem20 = twtFac->horizontalHeaderItem(8);
        ___qtablewidgetitem20->setText(QApplication::translate("Vendido", "Fecha", 0));
        QTableWidgetItem *___qtablewidgetitem21 = twtFac->horizontalHeaderItem(9);
        ___qtablewidgetitem21->setText(QApplication::translate("Vendido", "Hora", 0));
        QTableWidgetItem *___qtablewidgetitem22 = twtFac->horizontalHeaderItem(10);
        ___qtablewidgetitem22->setText(QApplication::translate("Vendido", "Descuento", 0));
        QTableWidgetItem *___qtablewidgetitem23 = twtFac->horizontalHeaderItem(11);
        ___qtablewidgetitem23->setText(QApplication::translate("Vendido", "Caja", 0));
    } // retranslateUi

};

namespace Ui {
    class Vendido: public Ui_Vendido {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENDIDO_H
