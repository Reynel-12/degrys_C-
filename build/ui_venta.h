/********************************************************************************
** Form generated from reading UI file 'venta.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTA_H
#define UI_VENTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Venta
{
public:
    QAction *actionAbrir;
    QAction *actionSalir;
    QAction *actionHistorial;
    QAction *actionAgregar_Inventario;
    QAction *actionIniciar_servidor;
    QAction *actionApagar_servidor;
    QAction *actionGenerar_reporte;
    QAction *actionClientes;
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QFormLayout *formLayout;
    QLineEdit *letCodBuscar;
    QPushButton *pbtCodBuscar;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *twtFacCaja1;
    QPushButton *pbtBorrarProdCaja1;
    QFormLayout *formLayout_3;
    QLineEdit *letTotalCaja1;
    QLabel *lblTotal_2;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *twtFacCaja2;
    QPushButton *pbtBorrarProdCaja2;
    QFormLayout *formLayout_4;
    QLineEdit *letTotalCaja2;
    QLabel *lblTotal_3;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QLabel *label_4;
    QLineEdit *letProducto;
    QGridLayout *gridLayout_6;
    QLineEdit *letTipo;
    QLabel *label_5;
    QGridLayout *gridLayout_5;
    QLineEdit *letInventario;
    QLabel *label_6;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLineEdit *letPrecio;
    QLabel *label_3;
    QPushButton *pbtAnadir;
    QGridLayout *gridLayout_3;
    QPushButton *pbtMas;
    QLabel *lblTotal;
    QLineEdit *letTotal;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbtVender;
    QPushButton *EliminarProd;
    QPushButton *pbtAgDescuento;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *letCajasConectadas;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *letPuerto;
    QGridLayout *gridLayout;
    QTableView *lvwDatabaseProd;
    QTableWidget *twtFac;
    QLabel *label_8;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuNegocio;
    QMenu *menuServidor;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Venta)
    {
        if (Venta->objectName().isEmpty())
            Venta->setObjectName(QStringLiteral("Venta"));
        Venta->resize(1739, 756);
        Venta->setStyleSheet(QStringLiteral(""));
        actionAbrir = new QAction(Venta);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/4213418_archive_documents_file_folder_office_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir->setIcon(icon);
        actionSalir = new QAction(Venta);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/4831032_door_entrance_exit_leave_logout_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalir->setIcon(icon1);
        actionHistorial = new QAction(Venta);
        actionHistorial->setObjectName(QStringLiteral("actionHistorial"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/8674989_ic_fluent_history_regular_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistorial->setIcon(icon2);
        actionAgregar_Inventario = new QAction(Venta);
        actionAgregar_Inventario->setObjectName(QStringLiteral("actionAgregar_Inventario"));
        actionIniciar_servidor = new QAction(Venta);
        actionIniciar_servidor->setObjectName(QStringLiteral("actionIniciar_servidor"));
        actionApagar_servidor = new QAction(Venta);
        actionApagar_servidor->setObjectName(QStringLiteral("actionApagar_servidor"));
        actionGenerar_reporte = new QAction(Venta);
        actionGenerar_reporte->setObjectName(QStringLiteral("actionGenerar_reporte"));
        actionClientes = new QAction(Venta);
        actionClientes->setObjectName(QStringLiteral("actionClientes"));
        centralWidget = new QWidget(Venta);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        letCodBuscar = new QLineEdit(centralWidget);
        letCodBuscar->setObjectName(QStringLiteral("letCodBuscar"));
        QFont font;
        font.setPointSize(12);
        letCodBuscar->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, letCodBuscar);

        pbtCodBuscar = new QPushButton(centralWidget);
        pbtCodBuscar->setObjectName(QStringLiteral("pbtCodBuscar"));
        QFont font1;
        font1.setPointSize(14);
        pbtCodBuscar->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, pbtCodBuscar);


        gridLayout_9->addLayout(formLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        twtFacCaja1 = new QTableWidget(centralWidget);
        if (twtFacCaja1->columnCount() < 6)
            twtFacCaja1->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twtFacCaja1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twtFacCaja1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twtFacCaja1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twtFacCaja1->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twtFacCaja1->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        twtFacCaja1->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        twtFacCaja1->setObjectName(QStringLiteral("twtFacCaja1"));
        twtFacCaja1->setFont(font);

        horizontalLayout_5->addWidget(twtFacCaja1);

        pbtBorrarProdCaja1 = new QPushButton(centralWidget);
        pbtBorrarProdCaja1->setObjectName(QStringLiteral("pbtBorrarProdCaja1"));
        pbtBorrarProdCaja1->setFont(font1);

        horizontalLayout_5->addWidget(pbtBorrarProdCaja1);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        letTotalCaja1 = new QLineEdit(centralWidget);
        letTotalCaja1->setObjectName(QStringLiteral("letTotalCaja1"));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        letTotalCaja1->setFont(font2);
        letTotalCaja1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, letTotalCaja1);

        lblTotal_2 = new QLabel(centralWidget);
        lblTotal_2->setObjectName(QStringLiteral("lblTotal_2"));
        lblTotal_2->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, lblTotal_2);


        gridLayout_2->addLayout(formLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        twtFacCaja2 = new QTableWidget(centralWidget);
        if (twtFacCaja2->columnCount() < 6)
            twtFacCaja2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        twtFacCaja2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        twtFacCaja2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        twtFacCaja2->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        twtFacCaja2->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        twtFacCaja2->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        twtFacCaja2->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        twtFacCaja2->setObjectName(QStringLiteral("twtFacCaja2"));
        twtFacCaja2->setFont(font);

        horizontalLayout_4->addWidget(twtFacCaja2);

        pbtBorrarProdCaja2 = new QPushButton(centralWidget);
        pbtBorrarProdCaja2->setObjectName(QStringLiteral("pbtBorrarProdCaja2"));
        pbtBorrarProdCaja2->setFont(font1);

        horizontalLayout_4->addWidget(pbtBorrarProdCaja2);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        letTotalCaja2 = new QLineEdit(centralWidget);
        letTotalCaja2->setObjectName(QStringLiteral("letTotalCaja2"));
        letTotalCaja2->setFont(font2);
        letTotalCaja2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, letTotalCaja2);

        lblTotal_3 = new QLabel(centralWidget);
        lblTotal_3->setObjectName(QStringLiteral("lblTotal_3"));
        lblTotal_3->setFont(font1);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, lblTotal_3);


        gridLayout_2->addLayout(formLayout_4, 3, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_2, 0, 2, 5, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);

        gridLayout_7->addWidget(label_4, 0, 0, 1, 1);

        letProducto = new QLineEdit(centralWidget);
        letProducto->setObjectName(QStringLiteral("letProducto"));
        letProducto->setFont(font1);

        gridLayout_7->addWidget(letProducto, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        letTipo = new QLineEdit(centralWidget);
        letTipo->setObjectName(QStringLiteral("letTipo"));
        letTipo->setFont(font1);

        gridLayout_6->addWidget(letTipo, 1, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font3);

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_6, 0, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        letInventario = new QLineEdit(centralWidget);
        letInventario->setObjectName(QStringLiteral("letInventario"));
        letInventario->setFont(font1);

        gridLayout_5->addWidget(letInventario, 1, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 0, 2, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font3);

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        letPrecio = new QLineEdit(centralWidget);
        letPrecio->setObjectName(QStringLiteral("letPrecio"));
        letPrecio->setFont(font1);

        gridLayout_4->addWidget(letPrecio, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 0, 3, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 1, 0, 1, 2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_3, 2, 0, 1, 1);

        pbtAnadir = new QPushButton(centralWidget);
        pbtAnadir->setObjectName(QStringLiteral("pbtAnadir"));
        pbtAnadir->setFont(font1);
        pbtAnadir->setFocusPolicy(Qt::WheelFocus);

        gridLayout_9->addWidget(pbtAnadir, 4, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pbtMas = new QPushButton(centralWidget);
        pbtMas->setObjectName(QStringLiteral("pbtMas"));
        QFont font4;
        font4.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        pbtMas->setFont(font4);

        gridLayout_3->addWidget(pbtMas, 0, 0, 1, 1);

        lblTotal = new QLabel(centralWidget);
        lblTotal->setObjectName(QStringLiteral("lblTotal"));
        lblTotal->setFont(font1);

        gridLayout_3->addWidget(lblTotal, 0, 1, 1, 1);

        letTotal = new QLineEdit(centralWidget);
        letTotal->setObjectName(QStringLiteral("letTotal"));
        letTotal->setFont(font2);
        letTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(letTotal, 0, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_3, 4, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pbtVender = new QPushButton(centralWidget);
        pbtVender->setObjectName(QStringLiteral("pbtVender"));
        pbtVender->setFont(font1);

        horizontalLayout_3->addWidget(pbtVender);

        EliminarProd = new QPushButton(centralWidget);
        EliminarProd->setObjectName(QStringLiteral("EliminarProd"));
        EliminarProd->setFont(font1);

        horizontalLayout_3->addWidget(EliminarProd);

        pbtAgDescuento = new QPushButton(centralWidget);
        pbtAgDescuento->setObjectName(QStringLiteral("pbtAgDescuento"));
        pbtAgDescuento->setFont(font1);

        horizontalLayout_3->addWidget(pbtAgDescuento);


        gridLayout_9->addLayout(horizontalLayout_3, 5, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        letCajasConectadas = new QLineEdit(centralWidget);
        letCajasConectadas->setObjectName(QStringLiteral("letCajasConectadas"));
        letCajasConectadas->setFont(font1);

        horizontalLayout_2->addWidget(letCajasConectadas);


        gridLayout_9->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        letPuerto = new QLineEdit(centralWidget);
        letPuerto->setObjectName(QStringLiteral("letPuerto"));
        letPuerto->setFont(font3);

        horizontalLayout->addWidget(letPuerto);


        gridLayout_9->addLayout(horizontalLayout, 6, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lvwDatabaseProd = new QTableView(centralWidget);
        lvwDatabaseProd->setObjectName(QStringLiteral("lvwDatabaseProd"));
        lvwDatabaseProd->setFont(font);

        gridLayout->addWidget(lvwDatabaseProd, 0, 0, 1, 1);

        twtFac = new QTableWidget(centralWidget);
        if (twtFac->columnCount() < 7)
            twtFac->setColumnCount(7);
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
        twtFac->setObjectName(QStringLiteral("twtFac"));
        twtFac->setFont(font);

        gridLayout->addWidget(twtFac, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout, 3, 0, 1, 2);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_8, 2, 1, 1, 1);

        Venta->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Venta);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1739, 26));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuNegocio = new QMenu(menuBar);
        menuNegocio->setObjectName(QStringLiteral("menuNegocio"));
        menuServidor = new QMenu(menuBar);
        menuServidor->setObjectName(QStringLiteral("menuServidor"));
        Venta->setMenuBar(menuBar);
        toolBar = new QToolBar(Venta);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Venta->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuNegocio->menuAction());
        menuBar->addAction(menuServidor->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuNegocio->addAction(actionHistorial);
        menuNegocio->addAction(actionAgregar_Inventario);
        menuNegocio->addAction(actionGenerar_reporte);
        menuNegocio->addAction(actionClientes);
        menuServidor->addAction(actionIniciar_servidor);
        menuServidor->addAction(actionApagar_servidor);
        toolBar->addAction(actionAbrir);
        toolBar->addAction(actionHistorial);
        toolBar->addSeparator();
        toolBar->addAction(actionSalir);

        retranslateUi(Venta);
        QObject::connect(actionAbrir, SIGNAL(triggered()), Venta, SLOT(Abrir()));
        QObject::connect(actionSalir, SIGNAL(triggered()), Venta, SLOT(close()));
        QObject::connect(pbtAnadir, SIGNAL(clicked()), Venta, SLOT(Anadir()));
        QObject::connect(pbtVender, SIGNAL(clicked()), Venta, SLOT(Vender()));
        QObject::connect(actionHistorial, SIGNAL(triggered()), Venta, SLOT(Historial()));
        QObject::connect(pbtCodBuscar, SIGNAL(clicked()), Venta, SLOT(BuscarCodProd()));
        QObject::connect(actionAgregar_Inventario, SIGNAL(triggered()), Venta, SLOT(anadirInventario()));
        QObject::connect(actionIniciar_servidor, SIGNAL(triggered()), Venta, SLOT(Iniciar()));
        QObject::connect(actionApagar_servidor, SIGNAL(triggered()), Venta, SLOT(Apagar()));
        QObject::connect(actionGenerar_reporte, SIGNAL(triggered()), Venta, SLOT(GenerarReporte()));
        QObject::connect(pbtAgDescuento, SIGNAL(clicked()), Venta, SLOT(AgregarDescuento()));
        QObject::connect(actionClientes, SIGNAL(triggered()), Venta, SLOT(VerClientes()));
        QObject::connect(pbtMas, SIGNAL(clicked()), Venta, SLOT(Mas()));

        QMetaObject::connectSlotsByName(Venta);
    } // setupUi

    void retranslateUi(QMainWindow *Venta)
    {
        Venta->setWindowTitle(QApplication::translate("Venta", "Venta", 0));
        actionAbrir->setText(QApplication::translate("Venta", "Abrir", 0));
        actionSalir->setText(QApplication::translate("Venta", "Salir", 0));
        actionHistorial->setText(QApplication::translate("Venta", "Historial", 0));
        actionAgregar_Inventario->setText(QApplication::translate("Venta", "Administraci\303\263n", 0));
        actionIniciar_servidor->setText(QApplication::translate("Venta", "Iniciar servidor", 0));
        actionApagar_servidor->setText(QApplication::translate("Venta", "Apagar servidor", 0));
        actionGenerar_reporte->setText(QApplication::translate("Venta", "Generar reporte", 0));
        actionClientes->setText(QApplication::translate("Venta", "Clientes", 0));
        letCodBuscar->setText(QString());
        pbtCodBuscar->setText(QApplication::translate("Venta", "Buscar", 0));
        QTableWidgetItem *___qtablewidgetitem = twtFacCaja1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Venta", "Codigo", 0));
        QTableWidgetItem *___qtablewidgetitem1 = twtFacCaja1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Venta", "Producto", 0));
        QTableWidgetItem *___qtablewidgetitem2 = twtFacCaja1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Venta", "Unidad", 0));
        QTableWidgetItem *___qtablewidgetitem3 = twtFacCaja1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Venta", "Cantidad", 0));
        QTableWidgetItem *___qtablewidgetitem4 = twtFacCaja1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Venta", "Precio", 0));
        QTableWidgetItem *___qtablewidgetitem5 = twtFacCaja1->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Venta", "SubTotal", 0));
        pbtBorrarProdCaja1->setText(QApplication::translate("Venta", "Borrar Producto", 0));
        letTotalCaja1->setText(QApplication::translate("Venta", "0", 0));
        lblTotal_2->setText(QApplication::translate("Venta", "Total:", 0));
        QTableWidgetItem *___qtablewidgetitem6 = twtFacCaja2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("Venta", "Codigo", 0));
        QTableWidgetItem *___qtablewidgetitem7 = twtFacCaja2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("Venta", "Producto", 0));
        QTableWidgetItem *___qtablewidgetitem8 = twtFacCaja2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("Venta", "Unidad", 0));
        QTableWidgetItem *___qtablewidgetitem9 = twtFacCaja2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("Venta", "Cantidad", 0));
        QTableWidgetItem *___qtablewidgetitem10 = twtFacCaja2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("Venta", "Precio", 0));
        QTableWidgetItem *___qtablewidgetitem11 = twtFacCaja2->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("Venta", "SubTotal", 0));
        pbtBorrarProdCaja2->setText(QApplication::translate("Venta", "Borrar Producto", 0));
        letTotalCaja2->setText(QApplication::translate("Venta", "0", 0));
        lblTotal_3->setText(QApplication::translate("Venta", "Total:", 0));
        label_4->setText(QApplication::translate("Venta", "Producto", 0));
        label_5->setText(QApplication::translate("Venta", "Tipo", 0));
        label_6->setText(QApplication::translate("Venta", "Inventario", 0));
        label_7->setText(QApplication::translate("Venta", "Precio", 0));
        label_3->setText(QApplication::translate("Venta", "Productos disponibles", 0));
        pbtAnadir->setText(QApplication::translate("Venta", "A\303\261adir al carrito", 0));
        pbtMas->setText(QApplication::translate("Venta", "+", 0));
        lblTotal->setText(QApplication::translate("Venta", "Total:", 0));
        letTotal->setText(QApplication::translate("Venta", "0", 0));
        pbtVender->setText(QApplication::translate("Venta", "Vender", 0));
        EliminarProd->setText(QApplication::translate("Venta", "Borrar Producto", 0));
        pbtAgDescuento->setText(QApplication::translate("Venta", "Agregar descuento", 0));
        label_2->setText(QApplication::translate("Venta", "Cajas conectadas:", 0));
        letCajasConectadas->setText(QApplication::translate("Venta", "0", 0));
        label->setText(QApplication::translate("Venta", "Puerto del servidor:", 0));
        letPuerto->setText(QApplication::translate("Venta", "69", 0));
        QTableWidgetItem *___qtablewidgetitem12 = twtFac->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("Venta", "Codigo", 0));
        QTableWidgetItem *___qtablewidgetitem13 = twtFac->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("Venta", "Producto", 0));
        QTableWidgetItem *___qtablewidgetitem14 = twtFac->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("Venta", "Unidad", 0));
        QTableWidgetItem *___qtablewidgetitem15 = twtFac->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("Venta", "Cantidad", 0));
        QTableWidgetItem *___qtablewidgetitem16 = twtFac->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("Venta", "Precio", 0));
        QTableWidgetItem *___qtablewidgetitem17 = twtFac->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QApplication::translate("Venta", "SubTotal", 0));
        QTableWidgetItem *___qtablewidgetitem18 = twtFac->horizontalHeaderItem(6);
        ___qtablewidgetitem18->setText(QApplication::translate("Venta", "Descuento", 0));
        label_8->setText(QApplication::translate("Venta", "Carrito", 0));
        menuArchivo->setTitle(QApplication::translate("Venta", "Archivo", 0));
        menuNegocio->setTitle(QApplication::translate("Venta", "Negocio", 0));
        menuServidor->setTitle(QApplication::translate("Venta", "Servidor", 0));
        toolBar->setWindowTitle(QApplication::translate("Venta", "Herramientas", 0));
    } // retranslateUi

};

namespace Ui {
    class Venta: public Ui_Venta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTA_H
