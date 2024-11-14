#include "nuevoproducto.h"
#include "ui_nuevoproducto.h"
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <windows.h>

nuevoProducto::nuevoProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevoProducto)
{
    ui->setupUi(this);
    setWindowTitle("Nuevo producto");

    QRegularExpression regExp("[0-9]+");
    QValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->letCodigo->setValidator(validator);
    ui->letInventario->setValidator(validator);
    ui->letPrecio->setValidator(validator);

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letCodigo->setStyleSheet(lineEditStyle);
    ui->letInventario->setStyleSheet(lineEditStyle);
    ui->letNombre->setStyleSheet(lineEditStyle);
    ui->letPrecio->setStyleSheet(lineEditStyle);
    ui->letUnidad->setStyleSheet(lineEditStyle);

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

nuevoProducto::~nuevoProducto()
{
    delete ui;
}

void nuevoProducto::on_buttonBox_accepted()
{
    if(ui->letCodigo->text().isEmpty() || ui->letNombre->text().isEmpty()
            || ui->letUnidad->text().isEmpty() || ui->letInventario->text().isEmpty()
            || ui->letPrecio->text().isEmpty()){
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Atencion", "Uno de los campos está vacio, debe rellenarlos todos");
        return;
    }
    accept();
}

QString nuevoProducto::codigo() const
{
    return ui->letCodigo->text();
}

QString nuevoProducto::nombre() const
{
    return ui->letNombre->text();
}

QString nuevoProducto::unidad() const
{
    return ui->letUnidad->text();
}

QString nuevoProducto::inventario() const
{
    return ui->letInventario->text();
}

QString nuevoProducto::precio() const
{
    return ui->letPrecio->text();
}

void nuevoProducto::on_buttonBox_rejected()
{
    reject();
}
