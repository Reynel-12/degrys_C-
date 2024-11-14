#include "vendido.h"
#include "ui_vendido.h"
#include "factura.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QRegularExpressionValidator>

#include <QFileDialog>
#include <QFile>
#include <QSqlTableModel>
#include <QSqlError>

#include <QPdfWriter>
#include <QPainter>
#include <QDate>
#include <QFontMetrics>
#include <windows.h>
#include "grafico.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "serverconfig.h"
#include "venta.h"

#define ACCESS "DRIVER={Microsoft Access Driver (*.mdb)};" \
"FIL={MS Access};DBQ=C:\\users\\Carlos salgado\\desktop\\Facturas.mdb"

    Vendido::Vendido(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vendido)
{
    ui->setupUi(this);
    setWindowTitle("Vendido");

    ui->letTotal->setReadOnly(true);
    ui->letTotal_2->setReadOnly(true);
    QStringList titulos, titulosFac;
    titulos <<"Factura"<<"Productos"<<"Tipo"<<"Cantidad"<<"SubTotal"<<"Total"<<"Cliente"<<"Cambio"<<"Fecha"<<"Hora";
    //titulosFac <<"Factura"<<"Productos"<<"Tipo"<<"Cantidad"<<"SubTotal"<<"Total"<<"Cliente"<<"Cambio"<<"Fecha"<<"Hora";
    //ui->twtVendido->setHorizontalHeaderLabels(titulos);
    ui->twtFac->setHorizontalHeaderLabels(titulosFac);

    QRegularExpression regExp("[0-9]+");
    QValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->letNoFac->setValidator(validator);

    ui->letFactura->setReadOnly(true);
    ui->letProducto->setReadOnly(true);
    ui->letTipo->setReadOnly(true);
    ui->letCantidad->setReadOnly(true);
    ui->letSubtotal->setReadOnly(true);
    ui->letTotalFac->setReadOnly(true);
    ui->letCliente->setReadOnly(true);
    ui->letCambio->setReadOnly(true);
    ui->letFecha->setReadOnly(true);
    ui->letHora->setReadOnly(true);
    ui->letPrecio->setReadOnly(true);
    ui->letDescuento->setReadOnly(true);

    connect(ui->lvwFac->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &Vendido::onRowSelected);
    connect(ui->twtFac->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &Vendido::SeleccionProdFac);

    connect(ui->cbxFiltros, &QComboBox::currentTextChanged, this, &Vendido::filterTable);

    //Boton busar
    QString searchButtonStyle = "QPushButton {"
                                "background-color: #6c757d;"  // Gris
                                "color: white;"
                                "border-radius: 5px;"
                                "padding: 5px;"
                                "}"
                                "QPushButton:hover {"
                                "background-color: #5a6268;"  // Gris oscuro al pasar el mouse
                                "}";

    //Boton añadir
    QString addButtonStyle = "QPushButton {"
                             "background-color: #007bff;"  // Azul
                             "color: white;"
                             "border-radius: 5px;"
                             "padding: 10px;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: #0069d9;"  // Azul oscuro al pasar el mouse
                             "}";

    //Boton vender
    QString sellButtonStyle = "QPushButton {"
                              "background-color: #28a745;"  // Verde
                              "color: white;"
                              "border-radius: 5px;"
                              "padding: 10px;"
                              "}"
                              "QPushButton:hover {"
                              "background-color: #218838;"  // Verde oscuro al pasar el mouse
                              "}";

    //Boton borrar producto
    QString deleteButtonStyle = "QPushButton {"
                                "background-color: #dc3545;"  // Rojo
                                "color: white;"
                                "border-radius: 5px;"
                                "padding: 10px;"
                                "}"
                                "QPushButton:hover {"
                                "background-color: #c82333;"  // Rojo oscuro al pasar el mouse
                                "}";

    ui->pbtNoFac->setStyleSheet(searchButtonStyle);
    ui->pbtNoFac->setToolTip("Buscar factura");

    ui->pbtGenerarReporte->setStyleSheet(addButtonStyle);
    ui->pbtGenerarReporte->setToolTip("Generar reporte");

    ui->pbtCargar->setStyleSheet(sellButtonStyle);
    ui->pbtCargar->setToolTip("Cargar facturas");

    ui->pushButton->setStyleSheet(deleteButtonStyle);
    ui->pushButton->setToolTip("Salir");

    ui->pbtGrafico->setStyleSheet(addButtonStyle);
    ui->pbtGrafico->setToolTip("Ver gráfico");

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

    ui->letPrecio->setStyleSheet(lineEditStyle);
    ui->letCambio->setStyleSheet(lineEditStyle);
    ui->letCantidad->setStyleSheet(lineEditStyle);
    ui->letCliente->setStyleSheet(lineEditStyle);
    ui->letFactura->setStyleSheet(lineEditStyle);
    ui->letFecha->setStyleSheet(lineEditStyle);
    ui->letHora->setStyleSheet(lineEditStyle);
    ui->letNoFac->setStyleSheet(lineEditStyle);
    ui->letProducto->setStyleSheet(lineEditStyle);
    ui->letSubtotal->setStyleSheet(lineEditStyle);
    ui->letTipo->setStyleSheet(lineEditStyle);
    ui->letTotal->setStyleSheet(lineEditStyle);
    ui->letTotalFac->setStyleSheet(lineEditStyle);
    ui->letTotal_2->setStyleSheet(lineEditStyle);
    ui->letDescuento->setStyleSheet(lineEditStyle);

    // Estilo moderno para QTableWidget
    QString tableWidgetStyle = R"(
            QTableWidget {
            background-color: #f5f5f5;
            alternate-background-color: #eaeaea;
            gridline-color: #dcdcdc;
            border: 1px solid #dcdcdc;
            border-radius: 10px;
}
            QTableWidget::item {
            padding: 10px;
}
            QTableWidget::item:selected {
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

    ui->twtFac->setStyleSheet(tableWidgetStyle);
    ui->lvwFac->setStyleSheet(tableWidgetStyle);

    // Estilo moderno para QComboBox
    QString comboBoxStyle = R"(
            QComboBox {
            background-color: #f5f5f5;
            border: 1px solid #dcdcdc;
            border-radius: 10px;
            padding: 5px;
            color: #333;
}
            QComboBox:focus {
            border: 1px solid #4a90e2;
            background-color: #ffffff;
}
            QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 20px;
            border-left: 1px solid #dcdcdc;
            border-top-right-radius: 10px;
            border-bottom-right-radius: 10px;
}
            QComboBox::down-arrow {
            image: url(:/Iconos/flecha-hacia-abajo.png);
            width: 10px;
            height: 10px;
}
            QComboBox QAbstractItemView {
            background-color: #ffffff;
            border: 1px solid #dcdcdc;
            selection-background-color: #4a90e2;
            selection-color: #ffffff;
}
            )";

    ui->cbxFiltros->setStyleSheet(comboBoxStyle);

    this->AbrirHistorial();
}

Vendido::~Vendido()
{
    delete ui;
}

void Vendido::BuscarFacTablasVend(const QString &texto, QTableView* tablaProd, QTableWidget* tablaDestino)
{
    double total = 0;

    // Verifica que el modelo de datos de la tabla de origen no sea nulo
    QAbstractItemModel* model = tablaProd->model();
    if (!model) {
        MessageBeep(MB_ICONHAND);
        QMessageBox::critical(this, "Error", "No se puede tener el modelo de datos");
        return;
    }

    // Limpia todas las filas de la tabla de destino antes de agregar nuevas filas
    for (int i = tablaDestino->rowCount() - 1; i >= 0; i--) {
        tablaDestino->removeRow(i);
    }

    bool facturaEncontrada = false;

    // Itera sobre las filas del modelo asociado al QTableView
    for (int fila = 0; fila < model->rowCount(); ++fila) {
        // Obtén el índice del número de factura (suponiendo que está en la columna 0)
        QModelIndex indexFactura = model->index(fila, 0);
        QVariant dataFactura = model->data(indexFactura);

        // Obtén el subtotal (suponiendo que está en la columna 4)
        QModelIndex indexSub = model->index(fila, 6);
        QVariant dataSub = model->data(indexSub);

        // Comprueba si el texto de búsqueda coincide con el número de factura en la fila actual
        if (dataFactura.toString() == texto) {
            facturaEncontrada = true;
            total += dataSub.toDouble();

            // Agrega una nueva fila a la tabla de destino (QTableWidget)
            int newRow = tablaDestino->rowCount();
            tablaDestino->insertRow(newRow);

            // Copia los datos de cada columna en la fila actual desde el modelo a la tabla de destino
            for (int columna = 0; columna < model->columnCount(); ++columna) {
                QModelIndex index = model->index(fila, columna);  // Índice de la celda actual
                QVariant data = model->data(index);  // Obtén el dato de la celda

                // Crea un nuevo QTableWidgetItem con el texto obtenido
                QTableWidgetItem *newItem = new QTableWidgetItem(data.toString());
                tablaDestino->setItem(newRow, columna, newItem);  // Agrega el ítem a la tabla de destino
            }

            // Selecciona la fila en la QTableView
            tablaProd->selectRow(fila);

            // Hacer que las celdas en la tabla de destino sean no editables
            for (int row = 0; row < tablaDestino->rowCount(); ++row) {
                for (int col = 0; col < tablaDestino->columnCount(); ++col) {
                    QTableWidgetItem *item = tablaDestino->item(row, col);
                    if (item) {
                        item->setFlags((item->flags() & ~Qt::ItemIsEditable) | Qt::ItemIsSelectable);
                    }
                }
            }
        }
    }

    // Actualiza el total en el campo de texto correspondiente
    ui->letTotal_2->setText(QString::number(total));

    // Ajusta el tamaño de las columnas y las filas para que se ajusten al contenido
    tablaDestino->resizeColumnsToContents();
    tablaDestino->resizeRowsToContents();

    // Muestra un mensaje dependiendo del resultado de la búsqueda
    if (facturaEncontrada) {
        this->SeleccionProd();
        MessageBeep(MB_OK);
        QMessageBox::information(this, "Añadir", "Factura encontrada");
    } else {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Error", "Factura no encontrada");
    }

    // Limpia el texto de búsqueda y la tabla de origen
    ui->letNoFac->setText("");
}



void Vendido::BuscarFac()
{
    this->BuscarFacTablasVend(ui->letNoFac->text(), ui->lvwFac, ui->twtFac);
}

void Vendido::AbrirHistorial()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = json_doc.object();
            QJsonArray products = json_obj["sales"].toArray();

            // Procesar los productos
            QStandardItemModel *standardModel = new QStandardItemModel(products.size(), 12, this);
            configurarEncabezados(standardModel);
            QStringList fechaFiltro;

            for (int i = 0; i < products.size(); ++i) {
                QJsonObject product = products[i].toObject();
                standardModel->setItem(i, 0, new QStandardItem(product["factura"].toString()));
                standardModel->setItem(i, 1, new QStandardItem(product["producto"].toString()));
                standardModel->setItem(i, 2, new QStandardItem(product["tipo"].toString()));
                standardModel->setItem(i, 3, new QStandardItem(QString::number(product["cantidad_vendida"].toInt())));
                standardModel->setItem(i, 4, new QStandardItem(product["precio"].toString()));
                standardModel->setItem(i, 5, new QStandardItem(product["descuento"].toString()));
                standardModel->setItem(i, 6, new QStandardItem(product["subtotal_venta"].toString()));
                standardModel->setItem(i, 7, new QStandardItem(product["total"].toString()));
                standardModel->setItem(i, 8, new QStandardItem(product["cliente"].toString()));
                standardModel->setItem(i, 9, new QStandardItem(product["cambio"].toString()));
                standardModel->setItem(i, 10, new QStandardItem(product["fecha_venta"].toString()));
                standardModel->setItem(i, 11, new QStandardItem(product["hora_venta"].toString()));

                // Obtener la fecha de venta
                QString fechaVenta = product["fecha_venta"].toString();

                // Añadir la fecha al filtro si aún no está en la lista
                if (!fechaFiltro.contains(fechaVenta)) {
                    fechaFiltro.append(fechaVenta);
                }
            }
            // Ordenar las fechas (opcional, si no vienen ya ordenadas)
            std::sort(fechaFiltro.begin(), fechaFiltro.end());

            // Mostrar solo los primeros 7 días
            QStringList primeros7Dias = fechaFiltro.mid(0, 7);

            // Añadir las fechas filtradas al QComboBox
            ui->cbxFiltros->addItems(primeros7Dias);

            ui->lvwFac->setModel(standardModel);
            ui->lvwFac->resizeColumnsToContents();
            ui->lvwFac->resizeRowsToContents();
            ui->lvwFac->setEditTriggers(QAbstractItemView::NoEditTriggers);
            connect(ui->lvwFac->selectionModel(), &QItemSelectionModel::currentChanged,
                    this, &Vendido::onRowSelected);
            this->filterTable("Hoy");
            // Cleanup
            reply->deleteLater();
        } else {
            qDebug() << "Error en la solicitud:" << reply->errorString();
        }
    });
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QNetworkRequest request(QUrl("http://"+v.IP+":5000/sales"));
    manager->get(request);
}

void Vendido::configurarEncabezados(QStandardItemModel *model)
{
    model->setHeaderData(0, Qt::Horizontal, "Factura");
    model->setHeaderData(1, Qt::Horizontal, "Productos");
    model->setHeaderData(2, Qt::Horizontal, "Tipo");
    model->setHeaderData(3, Qt::Horizontal, "Cantidad");
    model->setHeaderData(4, Qt::Horizontal, "Precio");
    model->setHeaderData(5, Qt::Horizontal, "Descuento");
    model->setHeaderData(6, Qt::Horizontal, "SubTotal");
    model->setHeaderData(7, Qt::Horizontal, "Total");
    model->setHeaderData(8, Qt::Horizontal, "Cliente");
    model->setHeaderData(9, Qt::Horizontal, "Cambio");
    model->setHeaderData(10, Qt::Horizontal, "Fecha");
    model->setHeaderData(11, Qt::Horizontal, "Hora");
}

void Vendido::onRowSelected(const QModelIndex &current)
{
    // Verifica que el índice seleccionado sea válido
    if (!current.isValid()) {
        qDebug() << "Índice no válido.";
        return;
    }

    // Usa el modelo `QSortFilterProxyModel` que contiene los datos filtrados
    QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->lvwFac->model());
    if (!proxyModel) {
        qDebug() << "Modelo no válido.";
        return;
    }

    // Obtiene el modelo fuente del proxy
    QAbstractItemModel *sourceModel = proxyModel->sourceModel();
    if (!sourceModel) {
        qDebug() << "Modelo fuente no válido.";
        return;
    }

    // Asegúrate de que el modelo tiene el número correcto de columnas
    if (sourceModel->columnCount() < 12) { // Ajusta el número de columnas según tus necesidades
        qDebug() << "Número de columnas insuficiente en el modelo.";
        return;
    }

    QStringList rowData;
    for (int column = 0; column < sourceModel->columnCount(); ++column) {
        QModelIndex sourceIndex = proxyModel->mapToSource(current.siblingAtColumn(column));
        QVariant data = sourceModel->data(sourceIndex);
        rowData.append(data.toString());
    }

    // Verifica que la lista de datos tenga suficientes elementos
    if (rowData.size() < 12) { // Ajusta el número de columnas según tus necesidades
        qDebug() << "Datos insuficientes para mostrar.";
        return;
    }

    // Actualiza los widgets con los datos de la fila seleccionada
    ui->letFactura->setText(rowData.at(0));
    ui->letProducto->setText(rowData.at(1));
    ui->letTipo->setText(rowData.at(2));
    ui->letCantidad->setText(rowData.at(3));
    ui->letPrecio->setText(rowData.at(4) + " Lps");
    ui->letDescuento->setText(rowData.at(5) + " Lps");
    ui->letSubtotal->setText(rowData.at(6) + " Lps");
    ui->letTotalFac->setText(rowData.at(7) + " Lps");
    ui->letCliente->setText(rowData.at(8) + " Lps");
    ui->letCambio->setText(rowData.at(9) + " Lps");
    ui->letFecha->setText(rowData.at(10));
    ui->letHora->setText(rowData.at(11));
}

void Vendido::limpiar()
{
    /*
    for(int i = ui->lvwFac->rowCount() - 1; i >= 0; i--) {
        ui->lvwFac->removeRow(i);
    }
*/
}

void Vendido::on_pushButton_clicked()
{
    accept();
}

void Vendido::SeleccionProd()
{
    // Obtener la fila seleccionada
    int Indice = ui->lvwFac->selectionModel()->currentIndex().row();

    // Verificar si hay una fila seleccionada
    if (Indice >= 0) {
        // Obtener el modelo asociado a la QTableView
        QAbstractItemModel* model = ui->lvwFac->model();

        // Verificar si el modelo no es nulo
        if (model) {
            // Obtener datos de todas las columnas de la fila seleccionada
            QStringList rowData;
            for (int col = 0; col < model->columnCount(); ++col) {
                // Obtiene el dato del modelo en la fila y columna correspondiente
                QString data = model->index(Indice, col).data().toString();
                rowData.append(data);
            }

            // Verificar que la cantidad de datos sea suficiente antes de acceder a ellos
            if (rowData.size() >= 12) {
                // Asignar los datos a los QLineEdit correspondientes
                ui->letFactura->setText(rowData.at(0));       // Número de factura
                ui->letProducto->setText(rowData.at(1));      // Producto
                ui->letTipo->setText(rowData.at(2));          // Tipo
                ui->letCantidad->setText(rowData.at(3));      // Cantidad
                ui->letSubtotal->setText(rowData.at(4) + " Lps"); // Subtotal
                ui->letTotalFac->setText(rowData.at(5) + " Lps");  // Total
                ui->letCliente->setText(rowData.at(6) + " Lps");   // Cliente
                ui->letCambio->setText(rowData.at(7) + " Lps");    // Cambio
                ui->letFecha->setText(rowData.at(8));         // Fecha
                ui->letHora->setText(rowData.at(9));          // Hora
                ui->letDescuento->setText(rowData.at(10) + " Lps"); // Descuento
                ui->letPrecio->setText(rowData.at(11));         // Caja
            } else {
                QMessageBox::warning(this, "Error", "No hay suficientes datos en la fila seleccionada.");
            }
        } else {
            QMessageBox::critical(this, "Error", "No se pudo obtener el modelo de la tabla.");
        }
    }
}

void Vendido::SeleccionProdFac()
{
    int Indice = ui->twtFac->selectionModel()->currentIndex().row();

    // Verificar si hay una fila seleccionada
    if (Indice >= 0) {
        // Obtener datos de todas las columnas de la fila seleccionada
        QStringList rowData;
        for (int col = 0; col < ui->twtFac->model()->columnCount(); ++col) {
            QString data = ui->twtFac->model()->index(Indice, col).data().toString();
            rowData.append(data);
        }

        // Concatenar los datos en una cadena y mostrarla en QLineEdit
        //QString rowDataString = rowData.join(" | ");
        ui->letFactura->setText(rowData.at(0));
        ui->letProducto->setText(rowData.at(1));
        ui->letTipo->setText(rowData.at(2));
        ui->letCantidad->setText(rowData.at(3));
        ui->letPrecio->setText(rowData.at(4) + " Lps");
        ui->letDescuento->setText(rowData.at(5) + " Lps");
        ui->letSubtotal->setText(rowData.at(6) + " Lps");
        ui->letTotalFac->setText(rowData.at(7) + " Lps");
        ui->letCliente->setText(rowData.at(8) + " Lps");
        ui->letCambio->setText(rowData.at(9) + " Lps");
        ui->letFecha->setText(rowData.at(10));
        ui->letHora->setText(rowData.at(11));



        // Ahora puedes acceder a cada elemento individualmente en rowData si lo necesitas
        // Por ejemplo: QString primerDato = rowData.at(0);
    }
}

void Vendido::crearPDF(QTableView *tableView, const QString &filePath) {
    // Configuración del archivo PDF
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);

    int yPosition = 0;
    int rowHeight = 75;
    QVector<int> columnWidths = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200}; // Anchos específicos para cada columna

    // Dibujar encabezados de columna
    int xPosition = 0;
    QAbstractItemModel *model = tableView->model();
    int columnCount = model->columnCount();
    int rowCount = model->rowCount();

    // Obtener los encabezados de columna desde el modelo
    for (int col = 0; col < columnCount; ++col) {
        QString headerText = model->headerData(col, Qt::Horizontal).toString();
        painter.drawText(xPosition, yPosition, columnWidths[col], rowHeight, Qt::AlignLeft, headerText);
        xPosition += columnWidths[col];
    }
    yPosition += rowHeight;

    // Dibujar filas de datos
    for (int row = 0; row < rowCount; ++row) {
        xPosition = 0;
        for (int col = 0; col < columnCount; ++col) {
            QModelIndex index = model->index(row, col);  // Acceder a los datos del modelo
            QString cellText = index.data().toString();  // Obtener el texto de la celda
            painter.drawText(xPosition, yPosition, columnWidths[col], rowHeight, Qt::AlignLeft, cellText);
            xPosition += columnWidths[col];
        }
        yPosition += rowHeight;
    }

    // Dibujar el total en el PDF
    painter.drawText(0, yPosition + rowHeight, "Total: " + ui->letTotal->text());

    // Finalizar la pintura
    painter.end();

}

void Vendido::GenerarReporte()
{
    QAbstractItemModel *modelP = ui->lvwFac->model();
    if (!modelP) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Generar reporte", "No se pudo obtener el modelo de la lista de productos.");
        return;
    }
    if (modelP->rowCount() == 0) {
        MessageBeep(MB_ICONEXCLAMATION);
        QMessageBox::warning(this, "Generar reporte", "No hay datos para generar un reporte.");
        return;
    }
    QDate currentDate = QDate::currentDate();
    QString fecha = "Facturas " + currentDate.toString("dd-MM-yyyy");
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", fecha, "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        crearPDF(ui->lvwFac, filePath);
    }
}

void Vendido::ajustarAnchoQLineEdit(QLineEdit *lineEdit)
{
    QFontMetrics metrics(lineEdit->font());
    int width = metrics.horizontalAdvance(lineEdit->text()) + 10;  // Añadir un pequeño margen
    lineEdit->setFixedWidth(width);
}

void Vendido::filterTable(const QString &text)
{
    QDate currentDate = QDate::currentDate();
    QString hoy = currentDate.toString("yyyy-MM-dd");
    double total = 0.0;
    double totalFiltro = 0.0;
    int filterColumn = 10; // La columna que deseas filtrar (fecha de venta)

    // Obtenemos el modelo y el proxyModel de la QTableView
    QAbstractItemModel* model = ui->lvwFac->model();
    QSortFilterProxyModel* proxyModel = qobject_cast<QSortFilterProxyModel*>(model);

    // Verificar si el modelo no es nulo
    if (!model) {
        QMessageBox::critical(this, "Error", "No se pudo obtener el modelo de la tabla.");
        return;
    }

    // Si no hay un proxyModel, usar directamente el modelo original
    if (!proxyModel) {
        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(model);
        ui->lvwFac->setModel(proxyModel);

        // Conectar el selectionModel una vez, al configurar el proxyModel
        connect(ui->lvwFac->selectionModel(), &QItemSelectionModel::currentChanged,
                this, &Vendido::onRowSelected);
    }

    if (text == "Hoy") {
        // Establecer el filtro para mostrar solo las filas con la fecha de hoy
        proxyModel->setFilterKeyColumn(filterColumn);
        proxyModel->setFilterRegularExpression(QRegularExpression(hoy, QRegularExpression::CaseInsensitiveOption)); // Usar expresión regular para mayor flexibilidad

        // Sumar los subtotales de las filas filtradas
        for (int row = 0; row < proxyModel->rowCount(); ++row) {
            QModelIndex indexSubtotal = proxyModel->index(row, 4); // Suponiendo que la columna 4 es el subtotal
            double subtotal = indexSubtotal.data().toDouble();
            totalFiltro += subtotal;
        }

        ui->letTotal->setText(QString::number(totalFiltro));
    }
    else if (text == "Todas las fechas") {
        // Limpiar cualquier filtro existente
        proxyModel->setFilterRegularExpression(QRegularExpression()); // Esto elimina cualquier filtro aplicado

        // Sumar el subtotal de todas las filas
        for (int row = 0; row < proxyModel->rowCount(); ++row) {
            QModelIndex indexSubtotal = proxyModel->index(row, 4); // Suponiendo que la columna 4 es el subtotal
            double subtotal = indexSubtotal.data().toDouble();
            total += subtotal;
        }

        ui->letTotal->setText(QString::number(total));
    }
    else {
        // Establecer el filtro para la columna de fecha
        proxyModel->setFilterKeyColumn(filterColumn);
        proxyModel->setFilterRegularExpression(QRegularExpression(text, QRegularExpression::CaseInsensitiveOption)); // Filtra por el texto seleccionado

        // Sumar los subtotales de las filas filtradas
        for (int row = 0; row < proxyModel->rowCount(); ++row) {
            QModelIndex indexSubtotal = proxyModel->index(row, 4); // Suponiendo que la columna 4 es el subtotal
            double subtotal = indexSubtotal.data().toDouble();
            totalFiltro += subtotal;
        }

        ui->letTotal->setText(QString::number(totalFiltro));
    }
}


void Vendido::on_pbtGrafico_clicked()
{
    grafico gr(this);
    gr.exec();
}
