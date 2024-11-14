#include "numerofactura.h"
#include "ui_numerofactura.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "serverconfig.h"
#include "venta.h"

numeroFactura::numeroFactura(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::numeroFactura)
{
    ui->setupUi(this);
    setWindowTitle("Número de factura");

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

    ui->spbNumFac->setStyleSheet(spinBoxStyle);

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

    QString lineEditStyle = R"(
        QLineEdit {
            background-color: #f5f5f5;
            border: 1px solid #dcdcdc;
            border-radius: 10px;
            padding: 10px;
            color: #333;
        }
        QLineEdit:focus {
            border: 1px solid #4a90e2;
            background-color: #ffffff;
        }
    )";

    ui->buttonBox->setStyleSheet(dialogButtonBoxStyle);
    ui->letFactAct->setStyleSheet(lineEditStyle);
    ui->letFactAct->setReadOnly(true);
    this->cargarFact();
}

numeroFactura::~numeroFactura()
{
    delete ui;
}

void numeroFactura::cargarFact()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            QJsonArray facturas = json_obj["factura"].toArray();
            QString numero;

            for (int i = 0; i < facturas.size(); ++i) {
                QJsonObject factura = facturas[i].toObject();
                numero = QString::number(factura["numero_factura"].toInt());
            }
            ui->letFactAct->setText(numero);

            reply->deleteLater();
        } else {
            qDebug() << "Error en la solicitud:" << reply->errorString();
        }
    });
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QNetworkRequest request(QUrl("http://"+v.IP+":5000/factura"));
    manager->get(request);
}

int numeroFactura::numFactura() const
{
    return ui->spbNumFac->value();
}
void numeroFactura::on_buttonBox_accepted()
{
    accept();
}

void numeroFactura::on_buttonBox_rejected()
{
    reject();
}
