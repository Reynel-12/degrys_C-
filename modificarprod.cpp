#include "modificarprod.h"
#include "ui_modificarprod.h"

modificarProd::modificarProd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modificarProd)
{
    ui->setupUi(this);
    setWindowTitle("Modificar productod");

    connect(ui->pbtCambiarCodigo, &QPushButton::clicked, this, &modificarProd::onCambiarCodigoClicked);
    connect(ui->pbtCambiarNombre, &QPushButton::clicked, this, &modificarProd::onCambiarNombreClicked);
    connect(ui->pbtCambiarUnidad, &QPushButton::clicked, this, &modificarProd::onCambiarUnidadClicked);
    connect(ui->CambiarPrecio, &QPushButton::clicked, this, &modificarProd::onCambiarPrecioClicked);
    connect(ui->pbtEliminarProd, &QPushButton::clicked, this, &modificarProd::onEliminarProductoClicked);

    // Configurar estilos para los botones
    ui->pbtCambiarCodigo->setStyleSheet("QPushButton {background-color: #2196F3; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #1E88E5;}");
    ui->pbtCambiarNombre->setStyleSheet("QPushButton {background-color: #2196F3; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #1E88E5;}");
    ui->pbtCambiarUnidad->setStyleSheet("QPushButton {background-color: #FFC107; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #FFB300;}");
    ui->CambiarPrecio->setStyleSheet("QPushButton {background-color: #FFC107; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #FFB300;}");
    ui->pbtEliminarProd->setStyleSheet("QPushButton {background-color: #F44336; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #E53935;}");
    ui->pbtSalir->setStyleSheet("QPushButton {background-color: #9E9E9E; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #757575;}");
}

modificarProd::~modificarProd()
{
    delete ui;
}

void modificarProd::on_pbtCambiarCodigo_clicked()
{
    accept();
}

void modificarProd::on_pbtCambiarNombre_clicked()
{
    accept();
}

void modificarProd::on_pbtCambiarUnidad_clicked()
{
    accept();
}

void modificarProd::on_CambiarPrecio_clicked()
{
    accept();
}

void modificarProd::onCambiarCodigoClicked()
{
    opcion = "Cambiar codigo";
}

void modificarProd::onCambiarNombreClicked()
{
    opcion = "Cambiar nombre";
}

void modificarProd::onCambiarUnidadClicked()
{
    opcion = "Cambiar unidad";
}

void modificarProd::onCambiarPrecioClicked()
{
    opcion = "Cambiar precio";
}

QString modificarProd::opcionActual() const
{
    return opcion;
}

void modificarProd::on_pbtSalir_clicked()
{
    reject();
}

void modificarProd::on_pbtEliminarProd_clicked()
{
    accept();
}

void modificarProd::onEliminarProductoClicked()
{
    opcion = "Eliminar producto";
}
