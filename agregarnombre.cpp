#include "agregarnombre.h"
#include "ui_agregarnombre.h"

agregarNombre::agregarNombre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarNombre)
{
    ui->setupUi(this);

    setWindowTitle("Agregar nombre");

    QString lineEditStyle = "QLineEdit { background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 5px; padding: 5px; } QLineEdit:focus { border: 1px solid #4a90e2; background-color: #ffffff;}";
    ui->letNombre->setStyleSheet(lineEditStyle);

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

agregarNombre::~agregarNombre()
{
    delete ui;
}

void agregarNombre::on_buttonBox_accepted()
{
    accept();
}

void agregarNombre::on_buttonBox_rejected()
{
    reject();
}

QString agregarNombre::nombre() const
{
    return ui->letNombre->text();
}
