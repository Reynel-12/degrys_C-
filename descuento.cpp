#include "descuento.h"
#include "ui_descuento.h"
#include <QMessageBox>
#include <windows.h>
#include <QRegularExpressionValidator>

descuento::descuento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::descuento)
{
    ui->setupUi(this);

    setWindowTitle("Descuento");

    QRegularExpression regExp("[0-9]+");
    QValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->letDescuento->setValidator(validator);

    ui->letTotal->setReadOnly(true);
    ui->letTotalDesc->setReadOnly(true);

    connect(ui->letDescuento, SIGNAL(textChanged(QString)), this, SLOT(restarNumeros()));
    connect(ui->letTotal, SIGNAL(textChanged(QString)), this, SLOT(restarNumeros()));

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letDescuento->setStyleSheet(lineEditStyle);
    ui->letTotal->setStyleSheet(lineEditStyle);
    ui->letTotalDesc->setStyleSheet(lineEditStyle);

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
}

descuento::~descuento()
{
    delete ui;
}

void descuento::on_buttonBox_accepted()
{
    if(ui->letDescuento->text().toInt() > ui->letTotal->text().toInt()){
        MessageBeep(MB_ICONASTERISK);
        QMessageBox::information(this, "Descuento", "El descuento no se puede aplicar");
        return;
    } else if(ui->letDescuento->text().toInt() <= ui->letTotal->text().toInt()){
        accept();
    }
}

void descuento::on_buttonBox_rejected()
{
    reject();
}

void descuento::setDatosCompartidos(const QString &datos)
{
    ui->letTotal->setText(datos);
}

void descuento::restarNumeros()
{
    QString texto1 = ui->letDescuento->text();
    QString texto2 = ui->letTotal->text();

    // Convertir los textos a números (usando toInt() para enteros o toDouble() para decimales)
    int numero1 = texto1.toInt();
    int numero2 = texto2.toInt();

    // Realizar la resta
    int resultado = numero2 - numero1;

    // Actualizar el texto del tercer QLineEdit con el resultado
    ui->letTotalDesc->setText(QString::number(resultado));
}


int descuento::Descuento() const
{
    return ui->letDescuento->text().toInt();
}

int descuento::TotalDesc() const
{
    return ui->letTotalDesc->text().toInt();
}

int descuento::Total() const
{
    return ui->letTotal->text().toInt();
}
