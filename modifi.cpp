#include "modifi.h"
#include "ui_modifi.h"
#include <QMessageBox>
#include <windows.h>

modifi::modifi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifi)
{
    ui->setupUi(this);
    setWindowTitle("Modificar");

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letCodigo->setStyleSheet(lineEditStyle);

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

modifi::~modifi()
{
    delete ui;
}

void modifi::on_btnConfiCancel_accepted()
{
    if(ui->letCodigo->text().isEmpty()){
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Advertencia", "Tiene que colocar el codigo del producto");
        return;
    }
    accept();
}

void modifi::on_btnConfiCancel_rejected()
{
    reject();
}

QString modifi::CodModi() const
{
    return ui->letCodigo->text();
}
