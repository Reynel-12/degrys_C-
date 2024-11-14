#include "contra.h"
#include "ui_contra.h"

contra::contra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contra)
{
    ui->setupUi(this);
    setWindowTitle("Ingresar contraseña");
    // Aplicar estilo a todos los QLineEdit en la ventana principal
    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letContrasena->setStyleSheet(lineEditStyle);

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

            ui->btnConfiCancel->setStyleSheet(dialogButtonBoxStyle);
}

contra::~contra()
{
    delete ui;
}

void contra::on_btnConfiCancel_accepted()
{
    accept();
}

void contra::on_btnConfiCancel_rejected()
{
    reject();
}

QString contra::Contrasena() const
{
    return ui->letContrasena->text();
}
