#include "cantidad.h"
#include "ui_cantidad.h"

Cantidad::Cantidad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cantidad)
{
    ui->setupUi(this);
    setWindowTitle("Cantidad");

    // Estilo moderno para QSpinBox
    QString spinBoxStyle = R"(
            QSpinBox {
            background-color: #f5f5f5;
            border: 1px solid #dcdcdc;
            border-radius: 10px;
            padding: 5px;
            color: #333;
}
            QSpinBox:focus {
            border: 1px solid #4a90e2;
            background-color: #ffffff;
}
            QSpinBox::up-button {
            background-color: #4a90e2;
            border: none;
            border-top-right-radius: 10px;
            border-bottom-left-radius: 10px;
}
            QSpinBox::up-button:hover {
            background-color: #357abd;
}
            QSpinBox::down-button {
            background-color: #4a90e2;
            border: none;
            border-top-left-radius: 10px;
            border-bottom-right-radius: 10px;
}
            QSpinBox::down-button:hover {
            background-color: #357abd;
}
            QSpinBox::up-arrow, QSpinBox::down-arrow {
width: 10px;
height: 10px;
color: white;
    }
    )";

    ui->sbxCantidad->setStyleSheet(spinBoxStyle);

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

            ui->bxAceptar->setStyleSheet(dialogButtonBoxStyle);
}

Cantidad::~Cantidad()
{
    delete ui;
}

void Cantidad::on_bxAceptar_accepted()
{
    accept();
}

void Cantidad::on_bxAceptar_rejected()
{
    reject();
}

int Cantidad::cantidad() const
{
    return ui->sbxCantidad->value();
}
