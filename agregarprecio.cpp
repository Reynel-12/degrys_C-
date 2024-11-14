#include "agregarprecio.h"
#include "ui_agregarprecio.h"
#include <QRegularExpressionValidator>

agregarPrecio::agregarPrecio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarPrecio)
{
    ui->setupUi(this);

    setWindowTitle("Agregar precio");

    QRegularExpression regExp("[0-9]+");
    QValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->letPrecio->setValidator(validator);

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letPrecio->setStyleSheet(lineEditStyle);

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

agregarPrecio::~agregarPrecio()
{
    delete ui;
}

void agregarPrecio::on_buttonBox_accepted()
{
    accept();
}

void agregarPrecio::on_buttonBox_rejected()
{
    reject();
}

QString agregarPrecio::precio() const
{
    return ui->letPrecio->text();
}
