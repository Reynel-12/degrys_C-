#include "opcionproductos.h"
#include "ui_opcionproductos.h"
#include <QFile>
#include <QMessageBox>

opcionProductos::opcionProductos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::opcionProductos)
{
    ui->setupUi(this);
    setWindowTitle("Menú");

    connect(ui->pbtAgInventario, &QPushButton::clicked, this, &opcionProductos::onAgregarInventarioClicked);
    connect(ui->btnAgNuevoProd, &QPushButton::clicked, this, &opcionProductos::onAgregarNuevoProductoClicked);
    connect(ui->btnModificarProd, &QPushButton::clicked, this, &opcionProductos::onModificarProductoClicked);
    connect(ui->pbtBorrarFac, &QPushButton::clicked, this, &opcionProductos::onBorrarFacturaClicked);
    connect(ui->pbtNumFac, &QPushButton::clicked, this, &opcionProductos::onNumeroFacturaClicked);
    connect(ui->pbtAgregarCliente, &QPushButton::clicked, this, &opcionProductos::onAgregarClienteClicked);

    // Establecer estilos
    ui->pbtAgInventario->setStyleSheet("QPushButton {background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #45a049;}");
    ui->btnAgNuevoProd->setStyleSheet("QPushButton {background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #45a049;}");
    ui->btnModificarProd->setStyleSheet("QPushButton {background-color: #FFC107; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #FFB300;}");
    ui->pbtBorrarFac->setStyleSheet("QPushButton {background-color: #F44336; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #E53935;}");
    ui->pbtNumFac->setStyleSheet("QPushButton {background-color: #2196F3; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #1E88E5;}");
    ui->pushButton->setStyleSheet("QPushButton {background-color: #9E9E9E; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #757575;}");
    ui->pbtAgregarCliente->setStyleSheet("QPushButton {background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #45a049;}");
}

opcionProductos::~opcionProductos()
{
    delete ui;
}

void opcionProductos::on_pbtAgInventario_clicked()
{
    accept();
    //opcion = "Agregar Inventario";
}
void opcionProductos::on_btnAgNuevoProd_clicked()
{
    accept();
}

void opcionProductos::on_btnModificarProd_clicked()
{
    accept();
}

void opcionProductos::onAgregarInventarioClicked() {
    opcionActual = "Agregar Inventario";
}

void opcionProductos::onAgregarNuevoProductoClicked() {
    opcionActual = "Agregar nuevo producto";
}

void opcionProductos::onModificarProductoClicked() {
    opcionActual = "Modificar producto";
}

void opcionProductos::onBorrarFacturaClicked() {
    opcionActual = "Borrar facturas";
}

void opcionProductos::onNumeroFacturaClicked() {
    opcionActual = "Numero de factura";
}

void opcionProductos::onAgregarClienteClicked() {
    opcionActual = "Agregar cliente";
}

QString opcionProductos::opcionProd() const
{
    return opcionActual;
}

void opcionProductos::on_pushButton_clicked()
{
    reject();
}

void opcionProductos::on_pbtBorrarFac_clicked()
{
    accept();
}

void opcionProductos::on_pbtNumFac_clicked()
{
    accept();
}

void opcionProductos::on_pbtAgregarCliente_clicked()
{
    accept();
}
