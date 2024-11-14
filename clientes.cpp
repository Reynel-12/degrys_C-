#include "clientes.h"
#include "ui_clientes.h"
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QMessageBox>
#include "venta.h"
#include "windows.h"
#include <QDebug>
#include "montocliente.h"
#include <QDate>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "serverconfig.h"

clientes::clientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientes)
{
    ui->setupUi(this);

    mModel = nullptr;

    setWindowTitle("Clientes");
    ui->letTotal->setReadOnly(true);
    ui->letSubTotal->setReadOnly(true);
    ui->letCantidad->setReadOnly(true);
    ui->letFecha->setReadOnly(true);
    ui->letProducto->setReadOnly(true);
    ui->letUnidad->setReadOnly(true);

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
    ui->tvwProductos->setStyleSheet(tableViewStyle);
    ui->tvwPagos->setStyleSheet(tableViewStyle);

    QString addButtonStyle = "QPushButton {"
                             "background-color: #007bff;"  // Azul
            "color: white;"
            "border-radius: 5px;"
            "padding: 10px;"
            "}"
            "QPushButton:hover {"
            "background-color: #0069d9;"  // Azul oscuro al pasar el mouse
            "}";

    ui->pbtConfirmar->setStyleSheet(addButtonStyle);
    ui->pbtConfirmar->setToolTip("Ver productos");

    QString sellButtonStyle = "QPushButton {"
                              "background-color: #28a745;"  // Verde
            "color: white;"
            "border-radius: 5px;"
            "padding: 10px;"
            "}"
            "QPushButton:hover {"
            "background-color: #218838;"  // Verde oscuro al pasar el mouse
            "}";

    ui->pbtCancelMonto->setStyleSheet(sellButtonStyle);
    ui->pbtCancelMonto->setToolTip("Cancelar monto");

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

    ui->letTotal->setStyleSheet(lineEditStyle);
    ui->letSubTotal->setStyleSheet(lineEditStyle);
    ui->letCantidad->setStyleSheet(lineEditStyle);
    ui->letFecha->setStyleSheet(lineEditStyle);
    ui->letProducto->setStyleSheet(lineEditStyle);
    ui->letUnidad->setStyleSheet(lineEditStyle);

    this->verClientes();
}

clientes::~clientes()
{
    delete ui;
}

void clientes::verClientes()
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

void clientes::conectarSeleccionFila()
{
    if (!mModel) {
        qDebug() << "Error: mModel es nullptr";
        return;
    }

    connect(ui->tvwProductos->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &clientes::actualizarDetallesProducto);
}

void clientes::actualizarDetallesProducto(const QModelIndex &current, const QModelIndex &)
{
    ui->tvwProductos->selectRow(current.row());

    QStringList rowData;
    for (int column = 0; column < mModel->columnCount(); ++column) {
        QModelIndex index = mModel->index(current.row(), column);
        QString cellText = mModel->data(index, Qt::DisplayRole).toString();
        rowData.append(cellText);
    }

    ui->letProducto->setText(rowData.at(2));
    ui->letUnidad->setText(rowData.at(3));
    ui->letCantidad->setText(rowData.at(4));
    ui->letSubTotal->setText(rowData.at(5) + " Lps");
    ui->letFecha->setText(rowData.at(6) + " Lps");
}

void clientes::CancelarMonto()
{
    QAbstractItemModel* model = ui->tvwClientes->model();
    QModelIndex index = ui->tvwClientes->selectionModel()->currentIndex();
    qDebug() << "Indice de fila seleccionada:" << index;

    if (!index.isValid()) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Añadir", "Por favor, seleccione un cliente de la lista.");
        return;
    }

    QString data = model->index(index.row(), 0).data().toString();
    QString datos = ui->letTotal->text();

    if (datos.toInt() == 0) {
        QMessageBox::information(this, "Atención", "El cliente no debe crédito");
        return;
    }

    qDebug() << "Monto: " << datos;

    montoCliente mc(this);
    mc.setDatosCompartidos(datos);
    if (mc.exec() == QDialog::Rejected) {
        QMessageBox::information(this, "Atención", "Se canceló la cancelación del monto");
        return;
    }

    QString monto = mc.monto();

    if (!this->actualizarTotalCliente(data, monto.toInt()) || !this->insertarPago(data, monto.toInt())) {
        return; // Si alguna consulta falla, se termina la función
    }

    int total = this->obtenerTotalCliente(data);
    ui->letTotal->setText(QString::number(total));

    QMessageBox::information(this, "Atención", "Se cancelaron " + monto + " LPS.");
    this->Confirmar();

    if (total == 0) {
        this->eliminarDatosCliente(data);
    }
}

bool clientes::actualizarTotalCliente(const QString& codigo, int monto)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Construir la URL para la solicitud
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QUrl url(QString("http://"+v.IP+":5000/clients/%1/update_total").arg(codigo));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Crear el JSON con el monto a actualizar
    QJsonObject json;
    json["monto"] = monto;
    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    // Enviar la solicitud PUT
    QNetworkReply *reply = manager->put(request, jsonData);

    // Usar un QEventLoop para esperar la respuesta de forma síncrona
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Manejar la respuesta
    if (reply->error() == QNetworkReply::NoError) {
        // Leer la respuesta JSON del servidor
        QByteArray response_data = reply->readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(response_data);
        QJsonObject responseObject = responseDoc.object();

        // Verificar si hubo un error en la respuesta
        if (responseObject.contains("error")) {
            QMessageBox::critical(this, "Error", "Error en la actualización: " + responseObject["error"].toString());
            reply->deleteLater();
            return false;
        }

        // Obtener el nuevo total del cliente
        int nuevoTotal = responseObject["NuevoTotalCliente"].toInt();
        qDebug() << "Nuevo total del cliente: " << nuevoTotal;
        ui->letTotal->setText(QString::number(nuevoTotal));

        // Opcional: Mostrar mensaje de éxito
        QMessageBox::information(this, "Éxito", "Total actualizado correctamente. Nuevo total: " + QString::number(nuevoTotal));
        reply->deleteLater();
        return true;
    } else {
        // Manejar el error en caso de que la solicitud falle
        QMessageBox::critical(this, "Error", "No se pudo actualizar el total: " + reply->errorString());
        reply->deleteLater();
        return false;
    }
}

bool clientes::insertarPago(const QString& codigo, int monto)
{
    // Obtener la fecha actual en formato "dd/MM/yyyy"
    QDate currentDate = QDate::currentDate();
    QString fecha = currentDate.toString("dd/MM/yyyy");

    // Crear el objeto JSON con los datos a enviar (monto y fecha)
    QJsonObject json;
    json["monto"] = monto;
    json["fecha"] = fecha;

    // Convertir el objeto JSON en un documento JSON
    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    // Crear el administrador de red para hacer la solicitud HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Construir la URL para la solicitud
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QUrl url(QString("http://"+v.IP+":5000/clients/%1/add_total").arg(codigo));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Enviar la solicitud POST al backend con los datos JSON
    QNetworkReply *reply = manager->post(request, jsonData);

    // Esperar la respuesta de forma síncrona
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Manejar la respuesta
    if (reply->error() == QNetworkReply::NoError) {
        // Leer la respuesta JSON del servidor
        QByteArray response_data = reply->readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(response_data);
        QJsonObject responseObject = responseDoc.object();

        // Verificar si hubo un error en la respuesta
        if (responseObject.contains("error")) {
            QMessageBox::critical(this, "Error", "Error al insertar el pago: " + responseObject["error"].toString());
            reply->deleteLater();
            return false;
        }

        // Si la inserción fue exitosa, mostrar un mensaje de éxito
        QMessageBox::information(this, "Éxito", "Pago insertado correctamente para el cliente: " + codigo);
        reply->deleteLater();
        return true;
    } else {
        // Manejar el error en caso de que la solicitud falle
        QMessageBox::critical(this, "Error", "No se pudo insertar el pago: " + reply->errorString());
        reply->deleteLater();
        return false;
    }
}

int clientes::obtenerTotalCliente(const QString& codigo)
{
    // Crear el administrador de red para hacer la solicitud HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Construir la URL para la solicitud
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QUrl url(QString("http://"+v.IP+":5000/clients/obtenerTotal/%1").arg(codigo));
    QNetworkRequest request(url);

    // Enviar la solicitud GET al backend
    QNetworkReply *reply = manager->get(request);

    // Esperar la respuesta de forma síncrona
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Manejar la respuesta
    int total = 0;
    if (reply->error() == QNetworkReply::NoError) {
        // Leer la respuesta JSON del servidor
        QByteArray response_data = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data);
        QJsonObject jsonObject = jsonDoc.object();

        // Verificar si la respuesta contiene el total
        if (jsonObject.contains("total") && jsonObject["total"].isArray()) {
            QJsonArray totalArray = jsonObject["total"].toArray();
            if (!totalArray.isEmpty()) {
                QJsonObject totalObject = totalArray.first().toObject();
                total = totalObject["totalCliente"].toInt();
            }
        } else {
            QMessageBox::critical(this, "Error", "No se encontró el total del cliente en la respuesta.");
        }
    } else {
        // Manejar el error en caso de que la solicitud falle
        QMessageBox::critical(this, "Error", "No se pudo obtener el total del cliente: " + reply->errorString());
    }

    // Limpiar
    reply->deleteLater();
    return total;
}

void clientes::eliminarDatosCliente(const QString& codigo)
{
    if (this->eliminarRegistros("ProductosClientes", codigo) && this->eliminarRegistros("Pagos", codigo)) {
        QMessageBox::information(this, "Atención", "El cliente ya no debe crédito y sus datos han sido eliminados.");
        this->Confirmar();
    }
}

bool clientes::eliminarRegistros(const QString& tabla, const QString& codigo)
{
    // Crear el administrador de red para hacer la solicitud HTTP
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Construir la URL para la solicitud
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QUrl url(QString("http://"+v.IP+":5000/delete_records/%1/%2").arg(tabla).arg(codigo));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Enviar la solicitud DELETE al backend
    QNetworkReply *reply = manager->deleteResource(request);

    // Esperar la respuesta de forma síncrona
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Manejar la respuesta
    if (reply->error() == QNetworkReply::NoError) {
        // Leer la respuesta JSON del servidor
        QByteArray response_data = reply->readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(response_data);
        QJsonObject responseObject = responseDoc.object();

        // Verificar si hubo un error en la respuesta
        if (responseObject.contains("error")) {
            QMessageBox::critical(this, "Error", "Error al eliminar registros: " + responseObject["error"].toString());
            reply->deleteLater();
            return false;
        }

        // Si la eliminación fue exitosa, mostrar un mensaje de éxito
        QMessageBox::information(this, "Éxito", "Registros eliminados correctamente.");
        reply->deleteLater();
        return true;
    } else {
        // Manejar el error en caso de que la solicitud falle
        QMessageBox::critical(this, "Error", "No se pudo eliminar los registros: " + reply->errorString());
        reply->deleteLater();
        return false;
    }
}

void clientes::Confirmar()
{
    QAbstractItemModel* model = ui->tvwClientes->model();
    QModelIndex index = ui->tvwClientes->selectionModel()->currentIndex();
    qDebug() << "Indice de fila seleccionada:" << index;

    if (!index.isValid()) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Añadir", "Por favor, seleccione un cliente de la lista.");
        return;
    }

    QString clienteCodigo = model->index(index.row(), 0).data().toString();

    int totalCliente = 0;

    if (!this->obtenerDatosCliente(clienteCodigo, ui->tvwProductos, ui->tvwPagos, totalCliente)) {
        return;
    }

    ui->letTotal->setText(QString::number(totalCliente));
}

bool clientes::obtenerDatosCliente(const QString& codigoCliente, QTableView *productosView, QTableView *pagosView, int& totalCliente)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QUrl url(QString("http://"+v.IP+":5000/clients/%1").arg(codigoCliente)); // URL de la API
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);

    // Usar un QEventLoop para esperar la respuesta
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Manejo de errores
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "Error", "No se pudo obtener los datos del cliente: " + reply->errorString());
        reply->deleteLater();
        return false;
    }

    // Leer la respuesta JSON
    QByteArray response_data = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data);
    QJsonObject jsonObject = jsonDoc.object();

    // Verificar si la respuesta tiene un error
    if (jsonObject.contains("error")) {
        QMessageBox::critical(this, "Error", "Error en el servidor: " + jsonObject["error"].toString());
        reply->deleteLater();
        return false;
    }

    // Crear un modelo para los productos
    QStandardItemModel *productosModel = new QStandardItemModel();
    productosModel->setHorizontalHeaderLabels({"Codigo Clientes", "Codigo Productos", "Nombre", "Unidad", "Cantidad", "SubTotal", "Fecha"});

    // Manejar los productos
    QJsonArray productosArray = jsonObject["Productos"].toArray();
    for (const QJsonValue &productoValue : productosArray) {
        QJsonObject producto = productoValue.toObject();
        QList<QStandardItem *> row;
        row.append(new QStandardItem(producto["CodigoClientes"].toString()));
        row.append(new QStandardItem(producto["CodigoProductos"].toString()));
        row.append(new QStandardItem(producto["Nombre"].toString()));
        row.append(new QStandardItem(producto["Unidad"].toString()));
        row.append(new QStandardItem(QString::number(producto["Cantidad"].toInt())));
        row.append(new QStandardItem(QString::number(producto["SubTotal"].toDouble())));
        row.append(new QStandardItem(producto["Fecha"].toString()));

        productosModel->appendRow(row);
    }

    // Asignar el modelo a la vista de productos
    productosView->setModel(productosModel);
    productosView->resizeColumnsToContents();
    productosView->resizeRowsToContents();
    productosView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Crear un modelo para los pagos
    QStandardItemModel *pagosModel = new QStandardItemModel();
    pagosModel->setHorizontalHeaderLabels({"Codigo Clientes", "Monto", "Fecha"});

    // Manejar los pagos
    QJsonArray pagosArray = jsonObject["Pagos"].toArray();
    for (const QJsonValue &pagoValue : pagosArray) {
        QJsonObject pago = pagoValue.toObject();
        QList<QStandardItem *> row;
        row.append(new QStandardItem(pago["CodigoClientes"].toString()));
        row.append(new QStandardItem(QString::number(pago["Monto"].toDouble())));
        row.append(new QStandardItem(pago["Fecha"].toString()));

        pagosModel->appendRow(row);
    }

    // Asignar el modelo a la vista de pagos
    pagosView->setModel(pagosModel);
    pagosView->resizeColumnsToContents();
    pagosView->resizeRowsToContents();
    pagosView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Obtener el total del cliente
    totalCliente = jsonObject["TotalCliente"].toInt();
    connect(productosView->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &clientes::onRowSelected);

    reply->deleteLater();
    return true;
}

void clientes::onRowSelected(const QModelIndex &current)
{
    // Verifica que el índice seleccionado sea válido
    if (!current.isValid()) {
        qDebug() << "Índice no válido.";
        return;
    }

    // Usa el modelo `QStandardItemModel` que contiene los datos de la API
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tvwProductos->model());

    if (!model) {
        qDebug() << "Modelo no válido.";
        return;
    }

    // Asegúrate de que el modelo tiene el número correcto de columnas
    if (model->columnCount() < 5) {
        qDebug() << "Número de columnas insuficiente en el modelo.";
        return;
    }

    QStringList rowData;
    for (int column = 0; column < model->columnCount(); ++column) {
        QStandardItem *item = model->item(current.row(), column);
        if (item) {
            rowData.append(item->text());
        } else {
            rowData.append(""); // Manejar caso de ítem no encontrado
        }
    }

    // Verifica que la lista de datos tenga suficientes elementos
    if (rowData.size() < 5) {
        qDebug() << "Datos insuficientes para mostrar.";
        return;
    }

    // Actualiza los widgets con los datos de la fila seleccionada
    ui->letProducto->setText(rowData.at(2));
    ui->letSubTotal->setText(rowData.at(5) + " Lps");
    ui->letCantidad->setText(rowData.at(4));
    ui->letFecha->setText(rowData.at(6));
    ui->letUnidad->setText(rowData.at(3));
}


bool clientes::ejecutarConsulta(const QString& consulta, QSqlQueryModel *model, int codigoCliente)
{
    QSqlQuery query;
    query.prepare(consulta);
    query.bindValue(":codigo", codigoCliente);

    if (!query.exec()) {
        return false;
    }

    model->setQuery(query);
    return true;
}

