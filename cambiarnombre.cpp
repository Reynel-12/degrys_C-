#include "cambiarnombre.h"
#include "ui_cambiarnombre.h"

cambiarNombre::cambiarNombre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cambiarNombre)
{
    ui->setupUi(this);
    setWindowTitle("Cambiar nombre");

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letnombre->setStyleSheet(lineEditStyle);

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

cambiarNombre::~cambiarNombre()
{
    delete ui;
}

void cambiarNombre::on_buttonBox_accepted()
{
    accept();
}

QString cambiarNombre::nombre() const
{
    return ui->letnombre->text();
}

void cambiarNombre::on_buttonBox_rejected()
{
    reject();
}
