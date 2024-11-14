#include "cambiarunidad.h"
#include "ui_cambiarunidad.h"

cambiarUnidad::cambiarUnidad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cambiarUnidad)
{
    ui->setupUi(this);
    setWindowTitle("Cambiar unidad");

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
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

cambiarUnidad::~cambiarUnidad()
{
    delete ui;
}

void cambiarUnidad::on_buttonBox_accepted()
{
    accept();
}

QString cambiarUnidad::unidad() const
{
    return ui->letUnidad->text();
}

void cambiarUnidad::on_buttonBox_rejected()
{
    reject();
}
