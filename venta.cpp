#include "venta.h"
#include "ui_venta.h"
#include "cantidad.h"
#include "vend.h"
#include "vuelto.h"
#include "vendido.h"
#include "factura.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QDate>
#include <algorithm>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QDialogButtonBox>
#include <QDialog>
#include <QRegularExpressionValidator>
#include <numeric>
#include <QNetworkInterface>
#include <QPdfWriter>
#include "numerofactura.h"
#include <windows.h>
#include "nuevocod.h"
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableFormat>
#include "descuento.h"
#include "clientes.h"
#include "seleccionarcliente.h"
#include "agregarnombre.h"
#include "agregarprecio.h"
#include "agregartipo.h"
#include <QStandardItemModel>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "serverconfig.h"
#include "invenoptimo.h"

Venta::Venta(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Venta), fac(1),
    mDbConnection("CARLOS_SALGADO", "SQL SERVER", "CARLOS_SALGADO\reyne", "", "Productos", true)
{
    ui->setupUi(this);

    mModel = nullptr;
    this->cargarUltimoNumeroFactura();
    this->setLineEditsReadOnly({ui->letTotal, ui->letProducto, ui->letTipo, ui->letInventario, ui->letPrecio});
    this->setLineEditsValidator({ui->letCodBuscar}, QRegularExpression("[0-9]+"));

    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &Venta::NuevaConexion);
    connect(this, &::Venta::contrasenaObtenida, this, &Venta::onContrasenaObtenida);

    this->applyButtonStyles();
    this->applyLineEditStyles();
    this->applyTableStyles();

    ui->pbtAgDescuento->setStyleSheet("QPushButton {background-color: #FFC107; color: white; border-radius: 5px; padding: 10px;} QPushButton:hover {background-color: #FFB300;}");
    ui->pbtAgDescuento->setCursor(Qt::PointingHandCursor);
    ui->pbtAgDescuento->setToolTip("Agregar descuento");

    resetTimer = new QTimer(this);
    resetTimer->setInterval(300); // 500 ms de tiempo de espera
    connect(resetTimer, &QTimer::timeout, this, &Venta::resetBarcodeData);

    qApp->installEventFilter(this);
    ui->letCodBuscar->setFocus();

    this->hideSecondaryElements();
}

void Venta::setLineEditsReadOnly(const QList<QLineEdit*>& lineEdits)
{
    for (auto lineEdit : lineEdits) {
        lineEdit->setReadOnly(true);
    }
}

void Venta::setLineEditsValidator(const QList<QLineEdit*>& lineEdits,
                                  const QRegularExpression& regExp)
{
    QValidator* validator = new QRegularExpressionValidator(regExp, this);
    for (auto lineEdit : lineEdits) {
        lineEdit->setValidator(validator);
    }
}

void Venta::applyButtonStyles()
{
    struct ButtonStyle {
        QPushButton* button;
        QString style;
        QString toolTip;
    };

    const QList<ButtonStyle> buttons = {
        {ui->pbtVender, "background-color: #28a745; color: white; border-radius: 5px; padding: 10px;", "Vender productos"},
        {ui->pbtAnadir, "background-color: #007bff; color: white; border-radius: 5px; padding: 10px;", "Añadir producto"},
        {ui->EliminarProd, "background-color: #dc3545; color: white; border-radius: 5px; padding: 10px;", "Eliminar producto"},
        {ui->pbtCodBuscar, "background-color: #6c757d; color: white; border-radius: 5px; padding: 5px;", "Buscar producto"},
        {ui->pbtMas, "background-color: #ffffff; color: green; border: 2px solid #e0e0e0; border-radius: 5px; padding: 10px 25px; font-weight: bold; text-align: center;", "Más"}
    };

    for (const auto& buttonStyle : buttons) {
        buttonStyle.button->setStyleSheet(buttonStyle.style);
        buttonStyle.button->setToolTip(buttonStyle.toolTip);
        buttonStyle.button->setCursor(Qt::PointingHandCursor);
    }
}

void Venta::applyLineEditStyles()
{
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

    const QList<QLineEdit*> lineEdits = {
        ui->letCodBuscar, ui->letProducto, ui->letTipo,
        ui->letInventario, ui->letPrecio, ui->letTotal,
        ui->letIP
    };

    for (auto lineEdit : lineEdits) {
        lineEdit->setStyleSheet(lineEditStyle);
    }
}

void Venta::applyTableStyles()
{
    QString tableWidgetStyle = R"(
        QTableWidget, QTableView {
            background-color: #f5f5f5;
            alternate-background-color: #eaeaea;
            gridline-color: #dcdcdc;
            border: 1px solid #dcdcdc;
            border-radius: 10px;
        }
        QTableWidget::item, QTableView::item {
            padding: 10px;
        }
        QTableWidget::item:selected, QTableView::item:selected {
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

    const QList<QTableWidget*> tableWidgets = {ui->twtFac};
    for (auto tableWidget : tableWidgets) {
        tableWidget->setStyleSheet(tableWidgetStyle);
    }

    ui->lvwDatabaseProd->setStyleSheet(tableWidgetStyle);
}

void Venta::hideSecondaryElements()
{
}

Venta::~Venta()
{
    delete ui;
}

int Venta::ultimoNumeroFactura = 1;

void Venta::Abrir()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            QJsonArray products = json_obj["products"].toArray();

            // Procesar los productos
            QStandardItemModel *standardModel = new QStandardItemModel(products.size(), 5, this);
            configurarEncabezados(standardModel);

            for (int i = 0; i < products.size(); ++i) {
                QJsonObject product = products[i].toObject();
                standardModel->setItem(i, 0, new QStandardItem(product["Codigo"].toString()));
                standardModel->setItem(i, 1, new QStandardItem(product["Nombre"].toString()));
                standardModel->setItem(i, 2, new QStandardItem(product["Unidad"].toString()));
                standardModel->setItem(i, 3, new QStandardItem(QString::number(product["Inventario"].toInt())));
                standardModel->setItem(i, 4, new QStandardItem(product["Precio"].toString()));
            }

            ui->lvwDatabaseProd->setModel(standardModel);
            ui->lvwDatabaseProd->resizeColumnsToContents();
            ui->lvwDatabaseProd->resizeRowsToContents();
            ui->lvwDatabaseProd->setEditTriggers(QAbstractItemView::NoEditTriggers);

            connect(ui->actionAbrir, &QAction::triggered, this, &Venta::Abrir);
            connect(ui->lvwDatabaseProd->selectionModel(), &QItemSelectionModel::currentChanged,
                    this, &Venta::onRowSelected);
            // Cleanup
            reply->deleteLater();
        } else {
            qDebug() << "Error en la solicitud:" << reply->errorString();
        }
    });
    QString ipAddress = serverConfig::instance().getIpAddress();
    QNetworkRequest request(QUrl("http://"+IP+":5000/products"));
    manager->get(request);
}

void Venta::configurarEncabezados(QStandardItemModel *model)
{
    model->setHeaderData(0, Qt::Horizontal, "Código");
    model->setHeaderData(1, Qt::Horizontal, "Nombre");
    model->setHeaderData(2, Qt::Horizontal, "Unidad");
    model->setHeaderData(3, Qt::Horizontal, "Inventario");
    model->setHeaderData(4, Qt::Horizontal, "Precio");
}

void Venta::llenarModelo(QStandardItemModel *model)
{
    for (int row = 0; row < mModel->rowCount(); ++row) {
        for (int column = 0; column < mModel->columnCount(); ++column) {
            QModelIndex index = mModel->index(row, column);
            QString cellText = mModel->data(index, Qt::DisplayRole).toString();
            QStandardItem *item = new QStandardItem(cellText);
            model->setItem(row, column, item);
        }
    }
}

void Venta::llenarProductos()
{
    mProductos.clear();
    for (int row = 0; row < mModel->rowCount(); ++row) {
        QStringList rowData;
        for (int column = 0; column < mModel->columnCount(); ++column) {
            QModelIndex index = mModel->index(row, column);
            QString cellText = mModel->data(index, Qt::DisplayRole).toString();
            rowData << cellText;
        }
        mProductos << rowData;
    }
}

void Venta::conectarSeleccionFila()
{
    if (!mModel) {
        qDebug() << "Error: mModel es nullptr";
        return;
    }

    connect(ui->lvwDatabaseProd->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &Venta::actualizarDetallesProducto);
}

void Venta::actualizarDetallesProducto(const QModelIndex &current, const QModelIndex &)
{
    ui->lvwDatabaseProd->selectRow(current.row());

    QStringList rowData;
    for (int column = 0; column < mModel->columnCount(); ++column) {
        QModelIndex index = mModel->index(current.row(), column);
        QString cellText = mModel->data(index, Qt::DisplayRole).toString();
        rowData.append(cellText);
    }

    ui->letProducto->setText(rowData.at(1));
    ui->letTipo->setText(rowData.at(2));
    ui->letInventario->setText(rowData.at(3));
    ui->letPrecio->setText(rowData.at(4) + " Lps");
}

void Venta::onRowSelected(const QModelIndex &current)
{
    // Verifica que el índice seleccionado sea válido
    if (!current.isValid()) {
        qDebug() << "Índice no válido.";
        return;
    }

    // Usa el modelo `QStandardItemModel` que contiene los datos de la API
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->lvwDatabaseProd->model());

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
    ui->letProducto->setText(rowData.at(1));
    ui->letTipo->setText(rowData.at(2));
    ui->letInventario->setText(rowData.at(3));
    ui->letPrecio->setText(rowData.at(4) + " Lps");
}


void Venta::Anadir()
{
    // Obtener el modelo de la lista de productos
    QAbstractItemModel *modelP = ui->lvwDatabaseProd->model();
    if (!modelP) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Añadir", "No se pudo obtener el modelo de la lista de productos.");
        return;
    }

    // Verificar si hay elementos en el modelo
    if (modelP->rowCount() == 0) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Añadir", "No hay productos disponibles para seleccionar.");
        return;
    }

    // Obtener la fila seleccionada
    QModelIndex index = ui->lvwDatabaseProd->selectionModel()->currentIndex();
    if (!index.isValid()) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Añadir", "Por favor, seleccione un producto de la lista.");
        return;
    }

    // Mostrar el diálogo de cantidad y obtener la cantidad seleccionada
    Cantidad cd(this);
    if (cd.exec() == QDialog::Rejected) return;

    int cantidad = cd.cantidad();
    if (cantidad <= 0) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Añadir", "La cantidad no puede ser 0");
        return;
    }

    // Obtener los datos de la fila seleccionada
    QStringList rowData;
    for (int col = 0; col < modelP->columnCount(); ++col) {
        rowData.append(modelP->index(index.row(), col).data().toString());
    }

    // Verificar si la cantidad seleccionada es válida
    int stock = rowData.at(3).toInt();
    if (cantidad > stock) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Añadir", "La cantidad seleccionada es mayor que el stock disponible.");
        return;
    }

    // Agregar o actualizar los datos en la factura
    int precio = rowData.at(4).toDouble();
    double totalpro = precio * cantidad;
    bool productoExistente = false;

    for (int row = 0; row < ui->twtFac->rowCount(); ++row) {
        if (ui->twtFac->item(row, CODFAC)->text() == rowData.at(0)) {
            // Producto encontrado, actualizar la cantidad y el subtotal
            int cantidadActual = ui->twtFac->item(row, CANTFAC)->text().toInt();
            int nuevaCantidad = cantidadActual + cantidad;
            ui->twtFac->item(row, CANTFAC)->setText(QString::number(nuevaCantidad));
            ui->twtFac->item(row, SUBFAC)->setText(QString::number(nuevaCantidad * precio));

            productoExistente = true;
            break;
        }
    }

    // Si el producto no existe, agregar una nueva fila
    if (!productoExistente) {
        int newRow = ui->twtFac->rowCount();
        ui->twtFac->insertRow(newRow);
        ui->twtFac->setItem(newRow, CODFAC, new QTableWidgetItem(rowData.at(0)));
        ui->twtFac->setItem(newRow, PRODFAC, new QTableWidgetItem(rowData.at(1)));
        ui->twtFac->setItem(newRow, TIPOFAC, new QTableWidgetItem(rowData.at(2)));
        ui->twtFac->setItem(newRow, CANTFAC, new QTableWidgetItem(QString::number(cantidad)));
        ui->twtFac->setItem(newRow, PRECIOFAC, new QTableWidgetItem(QString::number(precio)));
        ui->twtFac->setItem(newRow, SUBFAC, new QTableWidgetItem(QString::number(totalpro)));
        ui->twtFac->setItem(newRow, DESCUENTOFAC, new QTableWidgetItem("0"));
    }

    // Recalcular el total
    double totalpre = 0.0;
    for (int row = 0; row < ui->twtFac->rowCount(); ++row) {
        totalpre += ui->twtFac->item(row, SUBFAC)->text().toDouble();
    }
    ui->letTotal->setText(QString::number(totalpre));

    pr.push_back(totalpro);

    // Ajustar el tamaño de las columnas y filas
    ui->twtFac->resizeColumnsToContents();
    ui->twtFac->resizeRowsToContents();

    // Hacer que los elementos de la tabla no sean editables, pero sean seleccionables
    for (int row = 0; row < ui->twtFac->rowCount(); ++row) {
        for (int col = 0; col < ui->twtFac->columnCount(); ++col) {
            QTableWidgetItem *item = ui->twtFac->item(row, col);
            if (item) {
                item->setFlags((item->flags() & ~Qt::ItemIsEditable )| Qt::ItemIsSelectable);
            }
        }
    }
}

void Venta::Limpiar()
{
    ui->letTotal->setText("0");
    for(int i = ui->twtFac->rowCount() - 1; i >= 0; i--) {
        ui->twtFac->removeRow(i);
    }
    ui->letCodBuscar->setText("");
}

void Venta::AgregarDescuento()
{
    if (ui->twtFac->rowCount() == 0) {
        QMessageBox::warning(this, "Venta", "No se ha agregado ningún producto");
        return;
    }

    int filaSeleccionada = ui->twtFac->currentRow();
    if (filaSeleccionada < 0) {
        QMessageBox::information(this, "Atención", "Debe seleccionar un producto");
        return;
    }

    // Solicitar confirmación para agregar descuento
    QMessageBox::StandardButton respuesta = QMessageBox::question(this, "Atención", "¿Desea agregar descuento?", QMessageBox::Yes | QMessageBox::No);
    if (respuesta != QMessageBox::Yes) return;

    // Crear y configurar el diálogo de descuento
    descuento des(this);
    QString datos = ui->twtFac->item(filaSeleccionada, SUBFAC)->text();
    des.setDatosCompartidos(datos);
    if (des.exec() == QDialog::Rejected) return;

    // Obtener valores actuales y nuevos
    int precioOriginal = ui->twtFac->item(filaSeleccionada, SUBFAC)->text().toInt();
    int descuentoActual = ui->twtFac->item(filaSeleccionada, DESCUENTOFAC)->text().toInt();
    int nuevoDescuento = des.Descuento();

    // Aplicar descuento y actualizar el precio
    int precioConDescuento = precioOriginal - nuevoDescuento;
    if (precioConDescuento < 0) {
        precioConDescuento = 0;
    }

    // Actualizar la tabla con el nuevo precio y descuento
    ui->twtFac->item(filaSeleccionada, SUBFAC)->setText(QString::number(precioConDescuento));
    ui->twtFac->item(filaSeleccionada, DESCUENTOFAC)->setText(QString::number(descuentoActual + nuevoDescuento));

    // Recalcular el total
    double totalPre = 0.0;
    for (int row = 0; row < ui->twtFac->rowCount(); ++row) {
        totalPre += ui->twtFac->item(row, SUBFAC)->text().toDouble();
    }
    ui->letTotal->setText(QString::number(totalPre));
}

void Venta::VerClientes()
{
    clientes cl(this);
    cl.exec();
}

void Venta::Vender()
{
    try {
        QString noFac = QString::number(ultimoNumeroFactura);

        // Verificar si hay productos en la factura
        if (ui->twtFac->rowCount() == 0) {
            QMessageBox::warning(this, "Venta", "No se ha agregado ningún producto");
            return;
        }

        // Preguntar si se dará crédito
        QMessageBox::StandardButton respuestaCredito = QMessageBox::question(this, "Atención", "¿Se dará crédito a la venta?", QMessageBox::Yes | QMessageBox::No);
        if (respuestaCredito == QMessageBox::Yes) {
            SeleccionarCliente slc(this);
            if (slc.exec() == QDialog::Rejected) {
                QMessageBox::information(this, "Atención", "Se canceló el crédito");
                return;
            }

            QString codCliente = slc.codigoCliente();
            QString nombreCliente = slc.nombreCliente();
            if (codCliente.isEmpty()) {
                QMessageBox::warning(this, "Añadir", "Por favor, seleccione un cliente de la lista.");
                return;
            }

            QMessageBox::StandardButton confirmacionCredito = QMessageBox::question(this, "Atención", "¿Está seguro en darle crédito a " + nombreCliente + "?", QMessageBox::Yes | QMessageBox::No);
            if (confirmacionCredito == QMessageBox::No) {
                return;
            }

            // Procesar el crédito
            this->procesarCredito(codCliente);

            Fila.clear();
            FilaInvert.clear();
            pr.clear();
            this->Abrir();
            this->Limpiar();
            QMessageBox::information(this, "Atención", "Se dió crédito correctamente");
            return;
        }

        // Procesar venta sin crédito
        this->procesarVenta();

    } catch (const std::exception& e) {
        qDebug() << "Error: " << e.what();
        QMessageBox::warning(this, "Error", QString("Error: ") + e.what());
    }
}

void Venta::procesarCredito(const QString& codCliente)
{
    QMap<QString, int> productosCantidad;
    int numElementosLista = ui->twtFac->rowCount();

    // Agrupar las cantidades de productos iguales
    QJsonArray productosArray;
    for (int i = 0; i < numElementosLista; ++i) {
        QString codigoProducto = ui->twtFac->item(i, 0)->text(); // Código del producto
        int cantidad = ui->twtFac->item(i, CANTFAC)->text().toInt(); // Cantidad

        QJsonObject producto;
        producto["codigoProducto"] = codigoProducto;
        producto["nombre"] = ui->twtFac->item(i, 1)->text();
        producto["unidad"] = ui->twtFac->item(i, 2)->text();
        producto["cantidad"] = cantidad;
        producto["subtotal"] = ui->twtFac->item(i, 5)->text().toDouble();

        productosArray.append(producto);

        productosCantidad[codigoProducto] += cantidad;
    }

    // Preparar los datos para enviar
    QJsonObject json;
    json["codCliente"] = codCliente;
    json["productos"] = productosArray;
    json["total"] = ui->letTotal->text().toInt();

    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    // Enviar datos a la API REST
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString ipAddress = serverConfig::instance().getIpAddress();
    QUrl url("http://"+IP+":5000/process_credit");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, jsonData);

    // Manejar la respuesta
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
        QJsonObject jsonObj = jsonResponse.object();

        if (jsonObj.contains("error")) {
            QMessageBox::critical(this, "Error", "Error al procesar el crédito: " + jsonObj["error"].toString());
        } else {
            QMessageBox::information(this, "Éxito", "Crédito procesado correctamente.");
        }
    } else {
        QMessageBox::critical(this, "Error", "No se pudo procesar el crédito: " + reply->errorString());
    }

    reply->deleteLater();
}

void Venta::procesarVenta()
{
    QString datos = ui->letTotal->text();
    QDate currentDate = QDate::currentDate();
    QTime currentTime = QTime::currentTime();

    Vuelto vuelto(this);
    vuelto.setDatosCompartidos(datos);
    if (vuelto.exec() == QDialog::Rejected) return;

    int total = vuelto.Total();
    int cambio = vuelto.Cambio();
    int cliente = vuelto.Cliente();

    Vend v;
    v.NoFac = QString::number(ultimoNumeroFactura);
    v.Total = QString::number(total);
    v.Cambio = QString::number(cambio);
    v.Cliente = QString::number(cliente);
    v.Fecha = currentDate.toString("dd/MM/yyyy");
    v.Hora = currentTime.toString("hh:mm:ss");

    QMap<QString, int> productosCantidad;
    int numElementosLista = ui->twtFac->rowCount();

    // Crear un array JSON para los productos
    for (int i = 0; i < numElementosLista; ++i) {
        QString codigoProducto = ui->twtFac->item(i, 0)->text();
        QString nombreProducto = ui->twtFac->item(i, PRODFAC)->text();  // Nombre del producto
        QString tipoProducto = ui->twtFac->item(i, TIPOFAC)->text();  // Tipo del producto
        int cantidadProducto = ui->twtFac->item(i, CANTFAC)->text().toInt();  // Cantidad vendida
        double precioProducto = ui->twtFac->item(i, PRECIOFAC)->text().toDouble();  // Precio unitario
        double subTotalProducto = ui->twtFac->item(i, SUBFAC)->text().toDouble();  // Subtotal
        double descuentoProducto = ui->twtFac->item(i, DESCUENTOFAC)->text().toDouble();  // Descuento

        productosCantidad[codigoProducto] += cantidadProducto;

        // Crear el JSON para el producto actual
        QJsonObject productoJson;
        productoJson["Codigo"] = codigoProducto;
        productoJson["Nombre"] = nombreProducto;
        productoJson["Tipo"] = tipoProducto;
        productoJson["Cantidad"] = cantidadProducto;
        productoJson["Precio"] = precioProducto;
        productoJson["SubTotal"] = subTotalProducto;
        productoJson["Descuento"] = descuentoProducto;

        // Crear el JSON con los detalles generales de la venta para este producto
        QJsonObject ventaJson;
        ventaJson["Total"] = total;
        ventaJson["Cambio"] = cambio;
        ventaJson["Cliente"] = cliente;
        ventaJson["Fecha"] = currentDate.toString("yyyy-MM-dd");
        ventaJson["Hora"] = currentTime.toString("hh:mm:ss");

        // Añadir este producto al JSON de la venta
        QJsonArray productosArray;
        productosArray.append(productoJson);
        ventaJson["Productos"] = productosArray;

        // Convertir el objeto JSON a QByteArray para enviar como cuerpo de la solicitud HTTP
        QJsonDocument jsonDoc(ventaJson);
        QByteArray jsonData = jsonDoc.toJson();

        // Enviar la solicitud POST al servidor para este producto
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QString ipAddress = serverConfig::instance().getIpAddress();
        QNetworkRequest request(QUrl(QString("http://"+ipAddress+":5000/venta")));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        // Enviar el JSON para el producto actual
        QNetworkReply *reply = manager->post(request, jsonData);

        connect(reply, &QNetworkReply::finished, this, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                qDebug() << "Venta procesada exitosamente para producto: " << codigoProducto;
            } else {
                QMessageBox::warning(this, "Error", "Error en la solicitud de venta: " + reply->errorString());
                qDebug() << "Error en la solicitud de venta:" << reply->errorString();
            }
            reply->deleteLater();
        });
    }

    // Guardar los detalles de la factura y finalizar la venta
    for (int i = 0; i < ui->twtFac->rowCount(); ++i) {
        QTableWidgetItem* itemProd = ui->twtFac->item(i, PRODFAC);
        QTableWidgetItem* itemTipo = ui->twtFac->item(i, TIPOFAC);
        QTableWidgetItem* itemCant = ui->twtFac->item(i, CANTFAC);
        QTableWidgetItem* itemPrecio = ui->twtFac->item(i, PRECIOFAC);
        QTableWidgetItem* itemSubTotal = ui->twtFac->item(i, SUBFAC);
        QTableWidgetItem* itemDescuento = ui->twtFac->item(i, DESCUENTOFAC);

        if (!itemProd || !itemTipo || !itemCant || !itemPrecio || !itemSubTotal || !itemDescuento) {
            qWarning() << "Error: Elemento de la tabla no está inicializado en la fila" << i;
            continue;
        }

        v.Producto = itemProd->text();
        v.Tipo = itemTipo->text();
        v.Cantidad = itemCant->text();
        v.Precio = itemPrecio->text();
        v.SubTotal = itemSubTotal->text();
        v.Descuento = itemDescuento->text();
        VN.push_back(v);
    }

    copiaFac = VN;
    ultimoNumeroFactura++;
    this->guardarUltimoNumeroFactura();
    this->ImprimeFac();
    this->Abrir();
    this->Limpiar();
    Fila.clear();
    FilaInvert.clear();
    pr.clear();
    QMessageBox::information(this, "Venta", "Venta realizada");
    this->guardarDatos();
}

void Venta::Historial()
{
    Vendido *vendido = new Vendido(this);
    vendido->exec();
}

void Venta::ImprimeFac()
{
    try {
        // Verifica que ui->twtFac y ui->letTotal están correctamente inicializados
        if (!ui->twtFac || !ui->letTotal) {
            qWarning() << "Error: ui->twtFac o ui->letTotal no están inicializados.";
            return;
        }

        QString cliente;
        QString cambio;
        int descuento = 0;

        if (!copiaFac.isEmpty()) {
            const auto& ultimaFactura = copiaFac.last();
            cliente = ultimaFactura.Cliente;
            cambio = ultimaFactura.Cambio;

            for (int i = 0; i < ui->twtFac->rowCount(); ++i) {
                descuento += ui->twtFac->item(i, DESCUENTOFAC)->text().toInt();
            }
        } else {
            qWarning() << "Error: copiaFac está vacío.";
            return;
        }

        QPrinter printer;
        int noFac = ultimoNumeroFactura - 1;
        QPrintDialog dialog(&printer, this);

        if (dialog.exec() == QDialog::Accepted) {
            QPainter painter(&printer);
            QFont font("Courier", 10);
            painter.setFont(font);

            QTextDocument doc;
            QTextCursor cursor(&doc);

            QTextCharFormat boldFormat;
            boldFormat.setFontWeight(QFont::Bold);

            cursor.insertText("PULPERIA DEGRY'S\n", boldFormat);
            cursor.insertText("Villa de San Francisco, Barrio Arriba\n");
            cursor.insertText("Fecha y Hora: " + QDateTime::currentDateTime().toString() + "\n");
            cursor.insertText("Factura #" + QString::number(noFac) + "\n");
            cursor.insertText("-------------------------------------------------\n");

            QTextTableFormat tableFormat;
            tableFormat.setHeaderRowCount(1);
            tableFormat.setBorder(0);
            tableFormat.setCellPadding(2);
            tableFormat.setCellSpacing(2);

            QTextTable *table = cursor.insertTable(1, 4, tableFormat);

            agregarEncabezadosTabla(table, boldFormat);
            agregarProductosATabla(table);

            cursor.movePosition(QTextCursor::End);
            cursor.insertText("-------------------------------------------------\n");
            cursor.insertText("Descuento: " + QString::number(descuento) + "\n");
            cursor.insertText("Total: " + ui->letTotal->text() + "\n");
            cursor.insertText("Cliente: " + cliente + "\n");
            cursor.insertText("Cambio: " + cambio + "\n");
            cursor.insertText("\n**********GRACIAS POR SU COMPRA**********\n", boldFormat);

            doc.drawContents(&painter);
        }

        qDebug() << "Cliente: " << cliente;
        qDebug() << "Cambio: " << cambio;
        qDebug() << "Descuento: " << QString::number(descuento);
    } catch (const std::exception &e) {
        qWarning() << "Excepción capturada: " << e.what();
    } catch (...) {
        qWarning() << "Excepción desconocida capturada.";
    }
}

void Venta::agregarEncabezadosTabla(QTextTable *table, const QTextCharFormat &boldFormat)
{
    table->cellAt(0, 0).firstCursorPosition().insertText("Producto", boldFormat);
    table->cellAt(0, 1).firstCursorPosition().insertText("Cantidad", boldFormat);
    table->cellAt(0, 2).firstCursorPosition().insertText("Precio", boldFormat);
    table->cellAt(0, 3).firstCursorPosition().insertText("SubTotal", boldFormat);
}

void Venta::agregarProductosATabla(QTextTable *table)
{
    for (int i = 0; i < ui->twtFac->rowCount(); ++i) {
        QString producto = ui->twtFac->item(i, PRODFAC)->text();
        QString cantidad = ui->twtFac->item(i, CANTFAC)->text();
        QString precio = ui->twtFac->item(i, PRECIOFAC)->text();
        QString subTotal = ui->twtFac->item(i, SUBFAC)->text();

        int row = table->rows();
        table->insertRows(row, 1);
        table->cellAt(row, 0).firstCursorPosition().insertText(producto);
        table->cellAt(row, 1).firstCursorPosition().insertText(cantidad);
        table->cellAt(row, 2).firstCursorPosition().insertText(precio);
        table->cellAt(row, 3).firstCursorPosition().insertText(subTotal);
    }
}

void Venta::on_EliminarProd_clicked()
{
    int filaSeleccionada = ui->twtFac->currentRow();

    // Verificar si hay una fila seleccionada
    if (filaSeleccionada < 0) {
        QMessageBox::warning(this, "Error", "No hay un producto seleccionado");
        return;
    }

    // Confirmar eliminación del producto
    QMessageBox::StandardButton respuesta = QMessageBox::question(
        this,
        "Atención",
        "¿Está seguro de borrar este producto?",
        QMessageBox::Yes | QMessageBox::No
        );
    if (respuesta != QMessageBox::Yes) {
        return;
    }

    // Obtener subtotal de la fila seleccionada
    double subtotalFila = ui->twtFac->item(filaSeleccionada, SUBFAC)->text().toDouble();

    // Actualizar el total
    actualizarTotal(subtotalFila);

    // Eliminar la fila de la tabla
    ui->twtFac->removeRow(filaSeleccionada);

    // Actualizar la lista de productos (Fila)
    int totalFilas = ui->twtFac->rowCount();
    int filaInvert = totalFilas - filaSeleccionada - 1;
    if (filaInvert >= 0 && filaInvert < Fila.size()) {
        Fila.remove(filaInvert);
    } else {
        QMessageBox::warning(this, "Error", "Fila fuera de índice");
    }

    // Mostrar mensaje de éxito
    QMessageBox::information(this, "Atención", "Se eliminó el producto");
}

void Venta::actualizarTotal(double subtotalFila) {
    double suma = 0;
    for (int fila = 0; fila < ui->twtFac->rowCount(); ++fila) {
        QTableWidgetItem *item = ui->twtFac->item(fila, SUBFAC);
        if (item) {
            suma += item->text().toDouble();
        }
    }
    double nuevoTotal = suma - subtotalFila;
    pr.clear();
    pr.push_back(nuevoTotal);
    ui->letTotal->setText(QString::number(nuevoTotal));
}


void Venta::BuscarEnTabla(const QString &texto, QTableView* tabla)
{
    QAbstractItemModel* model = qobject_cast<QAbstractItemModel*>(tabla->model());
    if (!model) {
        MessageBeep(MB_ICONHAND);
        QMessageBox::critical(this, "Error", "No se puede tener el modelo de datos");
        return;
    }

    for (int fila = 0; fila < model->rowCount(); ++fila) {
        QModelIndex index = model->index(fila, 0);
        QVariant data = model->data(index);
        if (data.toString() == texto) {
            tabla->selectRow(fila); // Selecciona la fila donde se encontró el texto
            MessageBeep(MB_ICONASTERISK);
            QMessageBox::information(this, "Añadir", "Producto encontrado");
            this->Anadir();
            ui->letCodBuscar->setText("");
            return;
        }
    }
    MessageBeep(MB_ICONEXCLAMATION);
    QMessageBox::warning(this, "Error", "Producto no encontrado");
    ui->letCodBuscar->setText("");
}

void Venta::BuscarCodProd()
{
    this->BuscarEnTabla(ui->letCodBuscar->text(), ui->lvwDatabaseProd);
}

void Venta::RecibirCambioCliente(const QVector<Factura> &datos)
{
    CamCli = datos;
}

void Venta::cargarUltimoNumeroFactura()
{
    QString filename = "C:/Users/reyne/Desktop/ultimoNumeroFactura.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString ultimoNumero = in.readLine();
        ultimoNumeroFactura = ultimoNumero.toInt();
        file.close();
    }
}

void Venta::guardarUltimoNumeroFactura()
{
    QString filename = "C:/Users/reyne/Desktop/ultimoNumeroFactura.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ultimoNumeroFactura;
        file.close();
    }
}

void Venta::guardarDatos() {
    QString filename = "C:/Users/reyne/Desktop/DatosFactura.txt";
    QFile Escribe(filename);
    if (!Escribe.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        MessageBeep(MB_ICONHAND);
        QMessageBox::critical(this, "Pantalla Principal", "No se puede abrir el archivo");
        return;
    }
    QTextStream out(&Escribe);
    for (int i = 0; i < this->VN.size(); i++) {
        out << VN[i].NoFac + "|" <<
            VN[i].Producto + "|" <<
            VN[i].Tipo + "|" <<
            VN[i].Cantidad + "|" <<
            VN[i].SubTotal + "|" <<
            VN[i].Total + "|" <<
            VN[i].Cliente + "|" <<
            VN[i].Cambio + "|" <<
            VN[i].Fecha + "|" <<
            VN[i].Hora + "|" <<
            VN[i].Descuento + "|" <<
            "Caja principal" << Qt::endl;
        Escribe.flush();
    }
    MessageBeep(MB_ICONASTERISK);
    QMessageBox::information(this, "Factura", "Factura Guardada");
    VN.clear();
    Escribe.close();
}

void Venta::Mas()
{
    // Solicitar nombre del producto
    agregarNombre agName(this);
    if (agName.exec() == QDialog::Rejected) {
        return;
    }
    QString nombre = agName.nombre().isEmpty() ? "N/A" : agName.nombre();

    // Solicitar tipo de unidad
    agregarTipo agTi(this);
    if (agTi.exec() == QDialog::Rejected) {
        return;
    }
    QString unidad = agTi.unidad().isEmpty() ? "N/A" : agTi.unidad();

    // Solicitar precio del producto
    agregarPrecio agPre(this);
    if (agPre.exec() == QDialog::Rejected) {
        return;
    }
    QString precioStr = agPre.precio().isEmpty() ? "0" : agPre.precio();
    double precio = precioStr.toDouble();

    // Solicitar cantidad del producto
    Cantidad cant(this);
    if (cant.exec() == QDialog::Rejected) {
        return;
    }
    int cantidad = cant.cantidad();
    if (cantidad <= 0) {
        QMessageBox::warning(this, "Añadir", "La cantidad no puede ser 0");
        return;
    }

    // Insertar la nueva fila en la tabla
    int fila = ui->twtFac->rowCount();
    ui->twtFac->insertRow(fila);

    double subtotal = precio * cantidad;

    ui->twtFac->setItem(fila, CODFAC, new QTableWidgetItem("N/A"));
    ui->twtFac->setItem(fila, PRODFAC, new QTableWidgetItem(nombre));
    ui->twtFac->setItem(fila, TIPOFAC, new QTableWidgetItem(unidad));
    ui->twtFac->setItem(fila, CANTFAC, new QTableWidgetItem(QString::number(cantidad)));
    ui->twtFac->setItem(fila, PRECIOFAC, new QTableWidgetItem(QString::number(precio)));
    ui->twtFac->setItem(fila, SUBFAC, new QTableWidgetItem(QString::number(subtotal)));
    ui->twtFac->setItem(fila, DESCUENTOFAC, new QTableWidgetItem("0"));

    // Actualizar el total
    double total = 0.0;
    for (int row = 0; row < ui->twtFac->rowCount(); ++row) {
        total += ui->twtFac->item(row, SUBFAC)->text().toDouble();
    }
    ui->letTotal->setText(QString::number(total));

    // Añadir el subtotal al vector pr
    pr.push_back(subtotal);

    // Ajustar el tamaño de las columnas y filas
    ui->twtFac->resizeColumnsToContents();
    ui->twtFac->resizeRowsToContents();
}

void Venta::anadirInventario()
{
    // Verifica que el modelo esté disponible
    QAbstractItemModel *modelP = ui->lvwDatabaseProd->model();
    if (!modelP) {
        showWarning("La base de datos no está abierta.");
        return;
    }

    this->leerContrasenaDesdeArchivo();
}

void Venta::opcionesProductos(const QString& msg)
{
    // Maneja las opciones de productos con un mapa de funciones
    static const QMap<QString, std::function<void()>> opciones = {
        {"Agregar Inventario", [this]() { agregar_Inventario(); }},
        {"Agregar nuevo producto", [this]() { agregarNuevoProducto(); }},
        {"Modificar producto", [this]() { modificarProducto(); }},
        {"Borrar facturas", [this]() { borrarFacturas(); }},
        {"Numero de factura", [this]() { guardarNumeroFactura(); }},
        {"Agregar cliente", [this]() { agregar_Cliente(); }}
    };

    if (opciones.contains(msg)) {
        opciones[msg]();  // Ejecuta la función correspondiente a la opción
    } else {
        showWarning("Hubo un error u opción no disponible");
    }
}

bool Venta::verificarContrasena(const QString& Contrasena)
{
    contra cont(this);
    if (cont.exec() == QDialog::Rejected) return false;

    QString contralet = cont.Contrasena();
    QString contrasena = Contrasena;

    return contralet == contrasena;
}

void Venta::leerContrasenaDesdeArchivo()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            QJsonArray passwordArray = json_obj["password"].toArray();
            QString contraseña;

            for (int i = 0; i < passwordArray.size(); ++i) {
                QJsonObject pass = passwordArray[i].toObject();
                contraseña = pass["password"].toString();
            }
            qDebug() << "Contraseña obtenida:" << contraseña;

            // Emitir una señal o manejar la contraseña aquí
            emit contrasenaObtenida(contraseña);
        } else {
            qDebug() << "Error en la solicitud:" << reply->errorString();
        }
        reply->deleteLater(); // Limpieza de la respuesta
    });

    QString ipAddress = serverConfig::instance().getIpAddress(); // Obtener IP correctamente
    QNetworkRequest request(QUrl("http://" + IP + ":5000/password")); // Construcción correcta de la URL
    manager->get(request);
}

void Venta::onContrasenaObtenida(const QString& contraseñaArchivo)
{
    // Aquí llamamos a la verificación de la contraseña con el valor obtenido
    qDebug() << "Hasta aquí llegué";
    contra cont(this);
    if (cont.exec() == QDialog::Rejected) {
        showWarning("Contraseña incorrecta");
        return;
    }

    QString contralet = cont.Contrasena();  // Contraseña ingresada por el usuario
    if (contralet == contraseñaArchivo) {
        // Contraseña correcta, continuar con el proceso
        QString msg = obtenerOpcionProducto();
        if (!msg.isEmpty()) {
            opcionesProductos(msg);
        }
    } else {
        showWarning("Contraseña incorrecta");
    }
}

QString Venta::obtenerOpcionProducto()
{
    opcionProductos opProd(this);
    if (opProd.exec() == QDialog::Rejected) return QString();

    return opProd.opcionProd();
}

void Venta::agregar_Inventario()
{
    QString cod = obtenerCodigoProducto();
    if (cod.isEmpty()) return;

    // Llamar a la función asíncrona para obtener información del producto
    obtenerInformacionProducto(cod, [this, cod](const QString &resultado) {
        // Mostrar el resultado en una ventana de mensaje
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this, "Inventario", resultado, QMessageBox::Yes | QMessageBox::No
            );

        if (respuesta == QMessageBox::Yes) {
            // Solicitar al usuario el inventario adicional
            int inventarioAdicional = this->obtenerInventarioAdicional();
            if (inventarioAdicional == -1) return;

            // Intentar actualizar el inventario
            if (!this->actualizarInventario(cod, inventarioAdicional)) {
                this->showWarning("No se pudo actualizar el inventario.");
                return;
            }

            // Reabrir la ventana para reflejar los cambios
            this->Abrir();
            this->showInformation("El inventario ha sido actualizado correctamente.");
        } else {
            this->showInformation("Adición al inventario cancelada.");
        }
    });
}

QString Venta::obtenerCodigoProducto()
{
    agregarInventario inventario(this);
    if (inventario.exec() == QDialog::Rejected) return QString();

    return inventario.codigo();
}

void Venta::obtenerInformacionProducto(const QString &cod, ProductoCallback callback)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        QString textoCoincidencias;

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);

            if (json_doc.isObject()) {
                QJsonObject json_obj = json_doc.object();
                QJsonArray products = json_obj["products"].toArray();

                if (!products.isEmpty()) {
                    QJsonObject product = products[0].toObject();  // Si solo deseas el primer producto del array

                    if (!product.contains("error")) {
                        textoCoincidencias += "Codigo: " + product["Codigo"].toString() + "\n";
                        textoCoincidencias += "Nombre: " + product["Nombre"].toString() + "\n";
                        textoCoincidencias += "Unidad: " + product["Unidad"].toString() + "\n";
                        textoCoincidencias += "Inventario: " + QString::number(product["Inventario"].toInt()) + "\n";
                        textoCoincidencias += "Precio: " + product["Precio"].toString() + " LPS.\n";
                    } else {
                        textoCoincidencias = "Error: No se encontró el producto.";
                    }
                } else {
                    textoCoincidencias = "No se encontraron productos.";
                }
            }
        } else {
            textoCoincidencias = "Error en la solicitud: " + reply->errorString();
        }

        // Llamar al callback con el resultado
        callback(textoCoincidencias.isEmpty() ? QString() : "Este es el producto deseado:\n" + textoCoincidencias);

        reply->deleteLater();
    });

    // Crear y enviar la solicitud
    QString ipAddress = serverConfig::instance().getIpAddress();
    QUrl url(QString("http://"+IP+":5000/products/%1").arg(cod));
    QNetworkRequest request(url);
    manager->get(request);
}

int Venta::obtenerInventarioAdicional()
{
    numInventario inven(this);
    if (inven.exec() == QDialog::Rejected) return -1;

    return inven.inventario().toInt();
}

bool Venta::actualizarInventario(const QString &cod, int inventarioAdicional)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Crear la URL con el código del producto y la cantidad adicional
    QString ipAddress = serverConfig::instance().getIpAddress();
    QUrl url(QString("http://"+IP+":5000/products/%1/add/%2").arg(cod).arg(inventarioAdicional));

    // Crear la solicitud PUT
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Enviar la solicitud PUT
    QNetworkReply *reply = manager->put(request, QByteArray());

    // Manejar la respuesta
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    bool success = false;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);

        if (json_doc.isObject()) {
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                qDebug() << "Error al actualizar el inventario:" << json_obj["error"].toString();
            } else {
                qDebug() << "Inventario actualizado correctamente";
                success = true;
            }
        }
    } else {
        qDebug() << "Error en la solicitud: " << reply->errorString();
    }

    reply->deleteLater();
    return success;
}


void Venta::agregarNuevoProducto()
{
    nuevoProducto newProd(this);
    if (newProd.exec() == QDialog::Rejected) return;

    QString codigo = newProd.codigo();
    QString nombre = newProd.nombre();
    QString unidad = newProd.unidad();
    int inventario = newProd.inventario().toInt();
    double precio = newProd.precio().toDouble();

    // Verificar si el producto ya existe usando la API
    if (verificarCodigoProductoExistente(codigo)) {
        showWarning("El código del producto ya existe. No se puede agregar el producto.");
        return;
    }

    // Crear el objeto JSON con los datos del nuevo producto
    QJsonObject productJson;
    productJson["Codigo"] = codigo;
    productJson["Nombre"] = nombre;
    productJson["Unidad"] = unidad;
    productJson["Inventario"] = inventario;
    productJson["Precio"] = precio;

    QJsonDocument jsonDoc(productJson);
    QByteArray jsonData = jsonDoc.toJson();

    // Crear la solicitud POST
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString ipAddress = serverConfig::instance().getIpAddress();
    QUrl url("http://"+IP+":5000/products");  // Cambia la URL según sea necesario
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, jsonData);

    // Manejar la respuesta
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();
        if (json_obj.contains("error")) {
            showWarning("Error en la solicitud: " + json_obj["error"].toString());
        } else {
            this->Abrir();
            showInformation("Se agregó un nuevo producto.");
        }
    } else {
        showWarning("Error en la solicitud: " + reply->errorString());
    }

    reply->deleteLater();
}

bool Venta::verificarCodigoProductoExistente(const QString &codigo)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Crear la URL para la consulta del producto por código
    QString ipAddress = serverConfig::instance().getIpAddress();
    QUrl url(QString("http://"+IP+":5000/products/%1").arg(codigo));

    // Crear la solicitud GET
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Enviar la solicitud GET
    QNetworkReply *reply = manager->get(request);

    // Manejar la respuesta
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    bool exists = false;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);

        if (json_doc.isObject()) {
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                qDebug() << "Error en la consulta del producto:" << json_obj["error"].toString();
            } else {
                // Si el producto existe, el objeto JSON no debería estar vacío
                exists = !json_obj.isEmpty();
            }
        }
    } else {
        qDebug() << "Error en la solicitud: " << reply->errorString();
    }

    reply->deleteLater();
    return exists;
}

void Venta::modificarProducto()
{
    modificarProd modiPro(this);
    if (modiPro.exec() == QDialog::Rejected) return;

    QString resp = modiPro.opcionActual();
    if (resp == "Cambiar codigo") {
        this->cambiarCodigoProducto();
    } else if (resp == "Cambiar nombre") {
        this->cambiarNombreProducto();
    } else if (resp == "Cambiar unidad") {
        this->cambiarUnidadProducto();
    } else if (resp == "Cambiar precio") {
        this->cambiarPrecioProducto();
    } else if (resp == "Eliminar producto") {
        this->eliminarProducto();
    } else {
        this->showWarning("Opción no disponible");
    }
}

void Venta::cambiarCodigoProducto()
{
    QString codigoModificar = obtenerCodigoProducto();
    if (codigoModificar.isEmpty()) return;

    obtenerInformacionProducto(codigoModificar, [this, codigoModificar](const QString &resultado) {
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this, "Modificar Código", resultado, QMessageBox::Yes | QMessageBox::No
            );

        if (respuesta == QMessageBox::No) return;

        nuevoCod nC(this);
        if (nC.exec() == QDialog::Rejected) return;

        QString nuevoCodigo = nC.CodNew();
        if (verificarCodigoProductoExistente(nuevoCodigo)) {
            showWarning("El nuevo código ya existe en la base de datos. No se puede cambiar el código.");
            return;
        }

        // Crear el objeto JSON con el nuevo código
        QJsonObject updateJson;
        updateJson["Codigo"] = nuevoCodigo;

        QJsonDocument jsonDoc(updateJson);
        QByteArray jsonData = jsonDoc.toJson();

        // Crear la solicitud PUT para actualizar el código del producto
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QString ipAddress = serverConfig::instance().getIpAddress();
        QUrl url(QString("http://"+IP+":5000/products/updateCodigo/%1").arg(codigoModificar));  // Cambia la URL según sea necesario
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *reply = manager->put(request, jsonData);

        // Manejar la respuesta
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                showWarning("Error en la solicitud: " + json_obj["error"].toString());
            } else {
                this->Abrir();
                showInformation("El código del producto ha sido modificado correctamente.");
            }
        } else {
            showWarning("Error en la solicitud: " + reply->errorString());
        }

        reply->deleteLater();
    });
}

void Venta::cambiarNombreProducto()
{
    QString cod = obtenerCodigoProducto();
    if (cod.isEmpty()) return;

    obtenerInformacionProducto(cod, [this, cod](const QString &resultado) {
        // Aquí puedes usar el resultado, por ejemplo, actualizar una etiqueta o un campo de texto
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this, "Inventario", resultado, QMessageBox::Yes | QMessageBox::No
            );
        if (respuesta == QMessageBox::No) return;

        cambiarNombre newName(this);
        if (newName.exec() == QDialog::Rejected) return;

        QString nombre = newName.nombre();
        QJsonObject updateJson;
        updateJson["Nombre"] = nombre;

        QJsonDocument jsonDoc(updateJson);
        QByteArray jsonData = jsonDoc.toJson();

        // Crear la solicitud PUT para actualizar el código del producto
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QString ipAddress = serverConfig::instance().getIpAddress();
        QUrl url(QString("http://"+IP+":5000/products/updateName/%1").arg(cod));  // Cambia la URL según sea necesario
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *reply = manager->put(request, jsonData);

        // Manejar la respuesta
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                showWarning("Error en la solicitud: " + json_obj["error"].toString());
            } else {
                this->Abrir();
                showInformation("El producto ha sido modificado correctamente.");
            }
        } else {
            showWarning("Error en la solicitud: " + reply->errorString());
        }

        reply->deleteLater();
    });
}

void Venta::cambiarUnidadProducto()
{
    QString cod = obtenerCodigoProducto();
    if (cod.isEmpty()) return;

    obtenerInformacionProducto(cod, [this, cod](const QString &resultado) {
        // Aquí puedes usar el resultado, por ejemplo, actualizar una etiqueta o un campo de texto
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this, "Inventario", resultado, QMessageBox::Yes | QMessageBox::No
            );

        if (respuesta == QMessageBox::No) return;

        cambiarUnidad newUnidad(this);
        if (newUnidad.exec() == QDialog::Rejected) return;

        QString unidad = newUnidad.unidad();

        QJsonObject updateJson;
        updateJson["Unidad"] = unidad;

        QJsonDocument jsonDoc(updateJson);
        QByteArray jsonData = jsonDoc.toJson();

        // Crear la solicitud PUT para actualizar el código del producto
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QString ipAddress = serverConfig::instance().getIpAddress();
        QUrl url(QString("http://"+IP+":5000/products/updateUnidad/%1").arg(cod));  // Cambia la URL según sea necesario
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *reply = manager->put(request, jsonData);

        // Manejar la respuesta
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                showWarning("Error en la solicitud: " + json_obj["error"].toString());
            } else {
                this->Abrir();
                showInformation("El producto ha sido modificado correctamente.");
            }
        } else {
            showWarning("Error en la solicitud: " + reply->errorString());
        }

        reply->deleteLater();
    });
}

void Venta::cambiarPrecioProducto()
{
    QString cod = obtenerCodigoProducto();
    if (cod.isEmpty()) return;

    obtenerInformacionProducto(cod, [this, cod](const QString &resultado) {
        // Aquí puedes usar el resultado, por ejemplo, actualizar una etiqueta o un campo de texto
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this, "Inventario", resultado, QMessageBox::Yes | QMessageBox::No
            );

        if (respuesta == QMessageBox::No) return;

        cambiarPrecio newPrice(this);
        if (newPrice.exec() == QDialog::Rejected) return;

        QString precio = newPrice.precio();

        QJsonObject updateJson;
        updateJson["Precio"] = precio;

        QJsonDocument jsonDoc(updateJson);
        QByteArray jsonData = jsonDoc.toJson();

        // Crear la solicitud PUT para actualizar el código del producto
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QString ipAddress = serverConfig::instance().getIpAddress();
        QUrl url(QString("http://"+IP+":5000/products/updatePrecio/%1").arg(cod));  // Cambia la URL según sea necesario
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *reply = manager->put(request, jsonData);

        // Manejar la respuesta
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                showWarning("Error en la solicitud: " + json_obj["error"].toString());
            } else {
                this->Abrir();
                showInformation("El producto ha sido modificado correctamente.");
            }
        } else {
            showWarning("Error en la solicitud: " + reply->errorString());
        }

        reply->deleteLater();
    });
}

void Venta::eliminarProducto()
{
    QString cod = obtenerCodigoProducto();
    if (cod.isEmpty()) return;

    obtenerInformacionProducto(cod, [this, cod](const QString &resultado) {
        // Mostrar un mensaje de confirmación al usuario
        QMessageBox::StandardButton respuesta = QMessageBox::question(
            this, "Eliminar Producto", resultado, QMessageBox::Yes | QMessageBox::No
            );
        if (respuesta == QMessageBox::No) return;

        // Crear el objeto QNetworkAccessManager
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);

        // Construir la URL para la solicitud DELETE
        QString ipAddress = serverConfig::instance().getIpAddress();
        QUrl url(QString("http://"+IP+":5000/products/deleteProduct/%1").arg(cod));
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        // Enviar la solicitud DELETE
        QNetworkReply *reply = manager->deleteResource(request);

        // Manejar la respuesta
        QEventLoop loop;
        connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();

        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                showWarning("Error en la solicitud: " + json_obj["error"].toString());
            } else {
                this->Abrir();
                showInformation("El producto ha sido eliminado correctamente.");
            }
        } else {
            showWarning("Error en la solicitud: " + reply->errorString());
        }

        // Limpiar
        reply->deleteLater();
    });
}

void Venta::borrarFacturas()
{
    int resp = QMessageBox::question(
        this, "Confirmación", "¿Estás seguro de que deseas borrar todas las facturas?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (resp == QMessageBox::Yes) {
        QString filename = "C:/Users/reyne/Desktop/DatosFactura.txt";
        this->borrarContenidoArchivo(filename);
        showInformation("Se han borrado todas las facturas.");
        return;
    } else {
        showInformation("Operación cancelada.");
    }
}

void Venta::guardarNumeroFactura()
{
    numeroFactura nf(this);
    if (nf.exec() == QDialog::Rejected) return;

    QString numFactura = QString::number(nf.numFactura());
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Construir la URL para la solicitud
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QUrl url(QString("http://"+v.IP+":5000/factura/%1").arg(numFactura));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Enviar la solicitud PUT (ya no enviamos JSON, solo la URL con el número de factura)
    QNetworkReply *reply = manager->put(request, QByteArray());  // Vacío porque no mandamos cuerpo

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
            return;
        }

        // Obtener el nuevo total del cliente
        int nuevoTotal = responseObject["NuevoTotalCliente"].toInt();
        qDebug() << "Nuevo total del cliente: " << nuevoTotal;
        ui->letTotal->setText(QString::number(nuevoTotal));
        showInformation("Número de factura guardado correctamente.");
        reply->deleteLater();
        return;
    } else {
        showWarning("No se pudo guardar el número de factura. " + reply->errorString());
        reply->deleteLater();
        return;
    }
}

void Venta::agregar_Cliente()
{
    agregarNombre agNo(this);
    if (agNo.exec() == QDialog::Rejected) {
        this->showInformation("Se canceló la agregación de un cliente");
        return;
    }
    QString Nombre = agNo.nombre();

    QJsonObject json;
    json["Nombre"] = Nombre;
    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString ipAddress = serverConfig::instance().getIpAddress();
    QUrl url("http://"+IP+":5000/clients");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, jsonData);

    // Manejo de la respuesta
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            if (json_obj.contains("error")) {
                showWarning("Error en la solicitud: " + json_obj["error"].toString());
            } else {
                this->showInformation("Se agregó el nuevo cliente");
            }
        } else {
            showWarning("Error en la solicitud: " + reply->errorString());
        }
        reply->deleteLater();
    });
}

void Venta::showWarning(const QString &message)
{
    QMessageBox::warning(this, "Advertencia", message);
}

void Venta::showInformation(const QString &message)
{
    QMessageBox::information(this, "Información", message);
}

void Venta::Iniciar()
{

}

void Venta::Apagar()
{

}

void Venta::listening()
{

}

void Venta::NuevaConexion()
{

}

QString Venta::getClientIdForSocket(QTcpSocket *socket) {
    if (socketClientIdMap.contains(socket)) {
        return socketClientIdMap.value(socket);
    }
    return ""; // Devuelve una cadena vacía si no se encuentra el socket
}

void Venta::ClienteDesconectado(QString clientId, QTcpSocket *socket)
{

}

QString Venta::RecibiendoMensajes()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    QString message(data);

    qDebug() << "Data Recibida: " << message;

    if (message.startsWith("ID|")) {
        QString clientId = message.section('|', 1, 1);
        socketClientIdMap[socket] = clientId;
        qDebug() << "Client ID recibido: " << clientId;
        return "";
    }

    if (message.startsWith("DISCONNECT|")) {
        QString clientId = message.section('|', 1, 1);
        qDebug() << "Cliente " << clientId << " se ha desconectado.";
        ClienteDesconectado(clientId, socket);
        return "";
    }

    QString Resp = this->ProcesarProducto(message);
    QByteArray utf8Resp = Resp.toUtf8();
    socket->write(utf8Resp);
    socket->flush();
    socket->waitForBytesWritten(2000);
    return Resp;
}

QString Venta::ProcesarProducto(QString Mr)
{

}

void Venta::guardarDatosCaja1() {
    QString filename = "C:/Users/reyne/Desktop/DatosFactura.txt";
    QFile Escribe(filename);
    if (!Escribe.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        MessageBeep(MB_ICONHAND);
        QMessageBox::critical(this, "Pantalla Principal", "No se puede abrir el archivo");
        return;
    }
    QTextStream out(&Escribe);
    for (int i = 0; i < this->VNCaja1.size(); i++) {
        out << VNCaja1[i].NoFac + "|" <<
            VNCaja1[i].Producto + "|" <<
            VNCaja1[i].Tipo + "|" <<
            VNCaja1[i].Cantidad + "|" <<
            VNCaja1[i].SubTotal + "|" <<
            VNCaja1[i].Total + "|" <<
            VNCaja1[i].Cliente + "|" <<
            VNCaja1[i].Cambio + "|" <<
            VNCaja1[i].Fecha + "|" <<
            VNCaja1[i].Hora + "|" <<
            "Caja 1" << Qt::endl;
        Escribe.flush();
    }
    VNCaja1.clear();
    Escribe.close();
}

void Venta::guardarDatosCaja2() {
    QString filename = "C:/Users/reyne/Desktop/DatosFactura.txt";
    QFile Escribe(filename);
    if (!Escribe.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        MessageBeep(MB_ICONHAND);
        QMessageBox::critical(this, "Pantalla Principal", "No se puede abrir el archivo");
        return;
    }
    QTextStream out(&Escribe);
    for (int i = 0; i < this->VNCaja2.size(); i++) {
        out << VNCaja2[i].NoFac + "|" <<
            VNCaja2[i].Producto + "|" <<
            VNCaja2[i].Tipo + "|" <<
            VNCaja2[i].Cantidad + "|" <<
            VNCaja2[i].SubTotal + "|" <<
            VNCaja2[i].Total + "|" <<
            VNCaja2[i].Cliente + "|" <<
            VNCaja2[i].Cambio + "|" <<
            VNCaja2[i].Fecha + "|" <<
            VNCaja2[i].Hora + "|" <<
            "Caja 2" << Qt::endl;
        Escribe.flush();
        //}
    }
    VNCaja2.clear();
    Escribe.close();
}

void Venta::crearPDF(QTableView* tabla, const QString &filePath)
{
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);

    // Configuración de márgenes
    int leftMargin = 30;
    int topMargin = 30;
    int rightMargin = 30;
    int bottomMargin = 30;

    // Configuración de fuente
    QFont font("Arial", 10);
    painter.setFont(font);

    // Calcular anchos de columna basados en el contenido
    QAbstractItemModel *model = tabla->model();
    int columnCount = model->columnCount();
    int rowCount = model->rowCount();
    QVector<int> columnWidths(columnCount, 0);

    // Calcular el ancho del contenido más amplio para cada columna
    for (int col = 0; col < columnCount; ++col) {
        QFontMetrics metrics(font);
        int headerWidth = metrics.horizontalAdvance(model->headerData(col, Qt::Horizontal).toString());
        columnWidths[col] = headerWidth + 10; // Añadir un pequeño margen

        for (int row = 0; row < rowCount; ++row) {
            QModelIndex index = model->index(row, col);
            QString cellText = model->data(index).toString();
            int cellWidth = metrics.horizontalAdvance(cellText);
            if (cellWidth > columnWidths[col]) {
                columnWidths[col] = cellWidth + 10; // Añadir un pequeño margen
            }
        }
    }

    int yPosition = topMargin;
    int rowHeight = 75;
    int headerHeight = 50; // Altura específica para los encabezados

    // Título del documento
    QFont titleFont("Arial", 14, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(leftMargin, yPosition, pdfWriter.width() - leftMargin - rightMargin, headerHeight, Qt::AlignCenter, "Reporte de Ventas");
    yPosition += headerHeight + 20; // Espacio adicional debajo del título

    // Dibujar encabezados de columna
    QFont headerFont("Arial", 10, QFont::Bold);
    painter.setFont(headerFont);
    int xPosition = leftMargin;
    for (int col = 0; col < columnCount; ++col) {
        QRect headerRect(xPosition, yPosition, columnWidths[col], headerHeight);
        painter.drawRect(headerRect); // Dibujar borde de celda
        painter.drawText(headerRect, Qt::AlignCenter, model->headerData(col, Qt::Horizontal).toString());
        xPosition += columnWidths[col];
    }
    yPosition += headerHeight;

    // Dibujar filas de datos
    painter.setFont(font);
    for (int row = 0; row < rowCount; ++row) {
        xPosition = leftMargin;
        for (int col = 0; col < columnCount; ++col) {
            QModelIndex index = model->index(row, col);
            QString cellText = model->data(index).toString();
            QRect cellRect(xPosition, yPosition, columnWidths[col], rowHeight);
            painter.drawRect(cellRect); // Dibujar borde de celda
            painter.drawText(cellRect, Qt::AlignLeft | Qt::AlignVCenter, cellText);
            xPosition += columnWidths[col];
        }
        yPosition += rowHeight;
    }

    painter.end();
}

void Venta::GenerarReporte()
{
    QAbstractItemModel *modelP = ui->lvwDatabaseProd->model();
    if (!modelP) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Generar reporte", "No hay datos para generar un reporte.");
        return;
    }
    QDate currentDate = QDate::currentDate();
    QString producto = "Productos " + currentDate.toString("dd-MM-yyyy");
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save PDF", producto, "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        crearPDF(ui->lvwDatabaseProd, filePath);
    }
}

void Venta::borrarContenidoArchivo(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        MessageBeep(MB_ICONHAND);
        QMessageBox::critical(nullptr, "Error", "No se puede abrir el archivo para borrar su contenido");
        return;
    }
    file.close();
}

bool Venta::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->letCodBuscar && event->type() == QEvent::KeyPress) {
        auto* keyEvent = static_cast<QKeyEvent*>(event);
        int key = keyEvent->key();
        QString text = keyEvent->text();

        // Reiniciar el temporizador en cada pulsación de tecla
        resetTimer->start();

        // Verificar si el texto es un carácter imprimible
        if (QChar(text.at(0)).isPrint()) {
            barcodeData += text;
        } else if (key == Qt::Key_Return || key == Qt::Key_Enter) {
            procesarCodigoDeBarras();
        }

        return true; // Evento manejado
    }

    return QMainWindow::eventFilter(obj, event);
}

void Venta::procesarCodigoDeBarras()
{
    ui->letCodBuscar->setText(barcodeData);
    BuscarCodProd();
    barcodeData.clear();
    resetTimer->stop(); // Detener el temporizador después de un escaneo exitoso

    // Enfocar el letCodBuscar nuevamente
    ui->letCodBuscar->setFocus();
}

void Venta::resetBarcodeData()
{
    barcodeData.clear();
    resetTimer->stop();
}

void Venta::on_pbtBorrarProdCaja1_clicked()
{

}

void Venta::on_pbtBorrarProdCaja2_clicked()
{

}


void Venta::on_pbtConfigIP_clicked()
{
    IP = ui->letIP->text();
}

void Venta::inventarioOptimo()
{
    invenOptimo cl(this);
    cl.exec();
}
