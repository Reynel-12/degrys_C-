#include "montocliente.h"
#include "ui_montocliente.h"
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QDebug>

montoCliente::montoCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::montoCliente)
{
    ui->setupUi(this);

    setWindowTitle("Monto");

    QRegularExpression regExp("[0-9]+");
    QValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->letMonto->setValidator(validator);

    ui->letTotal->setReadOnly(true);
    ui->letCambio->setReadOnly(true);

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letMonto->setStyleSheet(lineEditStyle);
    ui->letTotal->setStyleSheet(lineEditStyle);
    ui->letCambio->setStyleSheet(lineEditStyle);

    QString dialogButtonBoxStyle = R"(
            QDialogButtonBox {
            background-color: #f0f0f0;
            border: none;
            padding: 10px;
}
            QDialogButtonBox QPushButton {
            background-color: #0078d7;
            color: white;
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            font-weight: bold;
}
            QDialogButtonBox QPushButton:hover {
            background-color: #005a9e;
}
            QDialogButtonBox QPushButton:pressed {
            background-color: #004578;
}
            QDialogButtonBox QPushButton:disabled {
            background-color: #c0c0c0;
            color: #f0f0f0;
}
            )";

            ui->buttonBox->setStyleSheet(dialogButtonBoxStyle);

    connect(ui->letMonto, SIGNAL(textChanged(QString)), this, SLOT(restarNumeros()));
    connect(ui->letTotal, SIGNAL(textChanged(QString)), this, SLOT(restarNumeros()));

}

montoCliente::~montoCliente()
{
    delete ui;
}

void montoCliente::setDatosCompartidos(const QString &datos)
{
    qDebug()<<"Monto a cancelar: "<<datos;
    ui->letTotal->setText(datos);
}

void montoCliente::on_buttonBox_accepted()
{
    if(ui->letMonto->text() != ""){
        if(ui->letMonto->text().toInt() <= ui->letTotal->text().toInt()){
            accept();
        } else {
            QMessageBox::information(this, "Atención" ,"El monto no es valido");
            return;
        }
    } else {
        QMessageBox::information(this, "Atención", "El monto no puede estar vacío");
    }
}

void montoCliente::on_buttonBox_rejected()
{
    reject();
}

QString montoCliente::monto() const
{
    return ui->letMonto->text();
}

void montoCliente::restarNumeros()
{
    QString texto1 = ui->letMonto->text();
    QString texto2 = ui->letTotal->text();

    // Convertir los textos a números (usando toInt() para enteros o toDouble() para decimales)
    int numero1 = texto1.toInt();
    int numero2 = texto2.toInt();

    // Realizar la resta
    int resultado = numero2 - numero1;

    // Actualizar el texto del tercer QLineEdit con el resultado
    ui->letCambio->setText(QString::number(resultado));
}
