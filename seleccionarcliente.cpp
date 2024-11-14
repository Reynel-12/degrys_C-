#include "seleccionarcliente.h"
#include "ui_seleccionarcliente.h"
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QMessageBox>
#include "windows.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "serverconfig.h"
#include "venta.h"

SeleccionarCliente::SeleccionarCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeleccionarCliente)
{
    ui->setupUi(this);

    mModel = nullptr;

    setWindowTitle("Seleccionar clientes");


    QString tableViewStyle = R"(
            QTableView {
            background-color: #f5f5f5;
            alternate-background-color: #eaeaea;
            gridline-color: #dcdcdc;
            border: 1px solid #dcdcdc;
            border-radius: 10px;
}
            QTableView::item {
            padding: 10px;
}
            QTableView::item:selected {
            background-color: #4a90e2;
            color: #ffffff;
}
            QHeaderView::section {
            background-color: #4a90e2;
            color: #ffffff;
            padding: 5px;
            border: 1px solid #dcdcdc;
            border-radius: 0px;
}
            QTableCornerButton::section {
            background-color: #4a90e2;
            border: 1px solid #dcdcdc;
}
            )";

            ui->tvwClientes->setStyleSheet(tableViewStyle);

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


    this->abrirClientes();
}

SeleccionarCliente::~SeleccionarCliente()
{
    delete ui;
}

void SeleccionarCliente::on_buttonBox_accepted()
{
    accept();
}

void SeleccionarCliente::on_buttonBox_rejected()
{
    reject();
}


QString SeleccionarCliente::codigoCliente() const
{
    QAbstractItemModel* model = ui->tvwClientes->model();
    QModelIndex index = ui->tvwClientes->selectionModel()->currentIndex();
    qDebug() << "Indice de fila seleccionada:" << index;
    if (!index.isValid()) {

        return "";
    }
    QString data = model->index(index.row(), 0).data().toString();

    return data;
}

QString SeleccionarCliente::nombreCliente() const
{
    QAbstractItemModel* model = ui->tvwClientes->model();
    QModelIndex index = ui->tvwClientes->selectionModel()->currentIndex();
    qDebug() << "Indice de fila seleccionada:" << index;
    if (!index.isValid()) {

        return "";
    }
    QString data = model->index(index.row(), 1).data().toString();

    return data;
}

void SeleccionarCliente::abrirClientes()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            QJsonArray clients = json_obj["clients"].toArray();

            // Procesar los productos
            QStandardItemModel *standardModel = new QStandardItemModel(clients.size(), 2, this);
            // Configurar los encabezados de las columnas
            QStringList headers = {"Código", "Nombre"};
            for (int i = 0; i < headers.size(); ++i) {
                standardModel->setHeaderData(i, Qt::Horizontal, headers[i]);
            }

            for (int i = 0; i < clients.size(); ++i) {
                QJsonObject client = clients[i].toObject();
                standardModel->setItem(i, 0, new QStandardItem(client["Codigo"].toString()));
                standardModel->setItem(i, 1, new QStandardItem(client["nombre"].toString()));
            }

            ui->tvwClientes->setModel(standardModel);
            ui->tvwClientes->resizeColumnsToContents();
            ui->tvwClientes->resizeRowsToContents();
            ui->tvwClientes->setEditTriggers(QAbstractItemView::NoEditTriggers);
            // Cleanup
            reply->deleteLater();
        } else {
            qDebug() << "Error en la solicitud:" << reply->errorString();
        }
    });
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QNetworkRequest request(QUrl("http://"+v.IP+":5000/clients"));
    manager->get(request);
}
