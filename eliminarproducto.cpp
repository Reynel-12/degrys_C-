#include "eliminarproducto.h"
#include "ui_eliminarproducto.h"

eliminarProducto::eliminarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eliminarProducto)
{
    ui->setupUi(this);
    setWindowTitle("Eliminar producto");

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

eliminarProducto::~eliminarProducto()
{
    delete ui;
}

void eliminarProducto::on_buttonBox_accepted()
{
    accept();
}

void eliminarProducto::on_buttonBox_rejected()
{
    reject();
}
