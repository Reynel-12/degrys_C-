#include "vuelto.h"
#include "ui_vuelto.h"
#include "venta.h"
#include "factura.h"
#include "vendido.h"
#include <QMetaObject>
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpressionValidator>
#include <windows.h>

Vuelto::Vuelto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vuelto)
{
    ui->setupUi(this);
    setWindowTitle("Vuelto");

    connect(ui->letCliente, SIGNAL(textChanged(QString)), this, SLOT(restarNumeros()));
    connect(ui->letTotal, SIGNAL(textChanged(QString)), this, SLOT(restarNumeros()));

    QRegularExpression regExp("[0-9]+");
    QValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->letCliente->setValidator(validator);

    ui->letTotal->setReadOnly(true);
    ui->letCambio->setReadOnly(true);

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letCambio->setStyleSheet(lineEditStyle);
    ui->letCliente->setStyleSheet(lineEditStyle);
    ui->letTotal->setStyleSheet(lineEditStyle);

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

            ui->btbConfir->setStyleSheet(dialogButtonBoxStyle);
}

Vuelto::~Vuelto()
{
    delete ui;
}

void Vuelto::setDatosCompartidos(const QString &datos)
{
    ui->letTotal->setText(datos);
}

void Vuelto::restarNumeros()
{
    QString texto1 = ui->letCliente->text();
    QString texto2 = ui->letTotal->text();

    // Convertir los textos a números (usando toInt() para enteros o toDouble() para decimales)
    int numero1 = texto1.toInt();
    int numero2 = texto2.toInt();

    // Realizar la resta
    int resultado = numero1 - numero2;

    // Actualizar el texto del tercer QLineEdit con el resultado
    ui->letCambio->setText(QString::number(resultado));
}

void Vuelto::on_btbConfir_accepted()
{
    if(ui->letCambio->text().toDouble() < 0){
        MessageBeep(MB_ICONASTERISK);
        QMessageBox::information(this,"Venta","Cliente no tiene suficiente dinero");
        return;
    }else if(ui->letCambio->text().toDouble() >= 0){
        accept();
    }
}

/*void Vuelto::agregarValor(int valor)
{
    Factura f;
    f.Cliente = QString::number(valor);
    Fac.push_back(f);
}*/

int Vuelto::Cambio() const
{
    return ui->letCambio->text().toInt();
}

int Vuelto::Cliente() const
{
    return ui->letCliente->text().toInt();
}

int Vuelto::Total() const
{
    return ui->letTotal->text().toInt();
}

void Vuelto::on_btbConfir_rejected()
{
    reject();
}
