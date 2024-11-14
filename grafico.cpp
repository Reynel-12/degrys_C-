#include "grafico.h"
#include "ui_grafico.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QVector>
#include <QStringList>
#include <QMap>
#include <QSet>
#include <limits>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

grafico::grafico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grafico)
{
    ui->setupUi(this);

    setWindowTitle("Gráfico de ventas");

    // Leer historial de facturas
        QVector<Facturas> facturas = leerHistorial("D:/Proyectos Qt/Pulperia1-2/InfoFactura/DatosFactura.txt");

        // Procesar datos
        QMap<int, QSet<int>> ventasPorHoraData = ventasPorHora(facturas);

        // Crear gráfica
        crearGraficoVentasPorHora(ventasPorHoraData);

        connect(ui->widget, &QCustomPlot::mouseMove, this, &grafico::actualizarTracer);
}

grafico::~grafico()
{
    delete ui;
}

void grafico::verGrafico()
{
}

QVector<Facturas> grafico::leerHistorial(const QString& archivo)
{
    QVector<Facturas> facturas;
    QFile file(archivo);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList campos = line.split('|');
            if (campos.size() >= 10) {
                Facturas factura;
                factura.id = campos[0].toInt();
                factura.producto = campos[1];
                factura.categoria = campos[2];
                factura.cantidad = campos[3].toInt();
                factura.precioUnitario = campos[4].toDouble();
                factura.total = campos[5].toDouble();
                factura.descuento = campos[6].toDouble();
                factura.totalFinal = campos[7].toDouble();
                factura.fechaHora = QDateTime::fromString(campos[8] + " " + campos[9], "dd/MM/yyyy HH:mm:ss");
                factura.caja = campos[10];
                facturas.append(factura);
            }
        }
        file.close();
    }
    return facturas;
}

QMap<int, QSet<int>> grafico::ventasPorHora(const QVector<Facturas>& facturas) {
    QMap<int, QSet<int>> ventas;
    for (const auto& factura : facturas) {
        int hora = factura.fechaHora.time().hour();
        ventas[hora].insert(factura.id); // Insertar el ID de la factura en el conjunto para esa hora
    }
    return ventas;
}

QMap<QString, int> grafico::ventasPorProducto(const QVector<Facturas>& facturas) {
    QMap<QString, int> ventas;
    for (const auto& factura : facturas) {
        ventas[factura.producto] += factura.cantidad;
    }
    return ventas;
}

QMap<QString, int> grafico::ventasPorCaja(const QVector<Facturas>& facturas) {
    QMap<QString, int> ventas;
    for (const auto& factura : facturas) {
        ventas[factura.caja] += factura.cantidad;
    }
    return ventas;
}

void grafico::crearGraficoVentasPorHora(const QMap<int, QSet<int>>& ventasPorHora) {
    QVector<double> horas, ventas;

    // Llenar los datos para cada hora del día
    for (int hora = 0; hora <= 23; ++hora) {
        horas.append(hora);
        if (ventasPorHora.contains(hora)) {
            ventas.append(ventasPorHora.value(hora).size()); // Tamaño del conjunto de ventas únicas
        } else {
            ventas.append(0); // No hay ventas para esta hora
        }
    }

    // Crear la gráfica
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(horas, ventas);

    // Configurar ejes
    ui->widget->xAxis->setLabel("Hora del día");
    ui->widget->yAxis->setLabel("Ventas");

    // Configurar el rango del eje X como enteros de 0 a 23
    QVector<double> tickVector;
    for (int i = 0; i <= 23; ++i) {
        tickVector.append(i);
    }
    ui->widget->xAxis->setRange(0, 23);

    // Configurar el rango del eje Y según las ventas máximas
    double maxVentas = *std::max_element(ventas.begin(), ventas.end()) + 1; // Añadir margen
    ui->widget->yAxis->setRange(0, maxVentas);

    // Crear y configurar el tracer
    tracer = new QCPItemTracer(ui->widget);
    tracer->setGraph(ui->widget->graph(0));
    tracer->setStyle(QCPItemTracer::tsCircle);
    tracer->setPen(QPen(Qt::red));
    tracer->setBrush(Qt::red);
    tracer->setSize(7);

    // Crear y configurar el texto del tracer
    tracerText = new QCPItemText(ui->widget);
    tracerText->position->setType(QCPItemPosition::ptPlotCoords);
    tracerText->setPositionAlignment(Qt::AlignTop | Qt::AlignHCenter);
    tracerText->setText("");
    tracerText->setFont(QFont(font().family(), 10));
    tracerText->setPen(QPen(Qt::black));
    tracerText->setBrush(QBrush(Qt::white));

    // Redibujar la gráfica
    ui->widget->replot();

    // Conectar la señal de mouse move al slot para actualizar el tracer
    connect(ui->widget, &QCustomPlot::mouseMove, this, &grafico::actualizarTracer);
}

void grafico::actualizarTracer(QMouseEvent *event) {
    // Convertir la posición del mouse a coordenadas del gráfico
    double x = ui->widget->xAxis->pixelToCoord(event->pos().x());
    double y = ui->widget->yAxis->pixelToCoord(event->pos().y());

    // Obtener los datos de la gráfica
    QCPGraph *graph = ui->widget->graph(0);
    auto data = graph->data();

    // Encuentra el índice más cercano
    int closestIndex = -1;
    double minDistance = std::numeric_limits<double>::max();

    // Iterar sobre los puntos de datos para encontrar el más cercano
    for (int i = 0; i < data->size(); ++i) {
        auto point = data->at(i);
        double key = point->key;
        double distance = std::abs(key - x);
        if (distance < minDistance) {
            minDistance = distance;
            closestIndex = i;
        }
    }

    if (closestIndex != -1) {
        auto point = data->at(closestIndex);
        double key = point->key;
        double value = point->value;

        // Actualizar el tracer
        tracer->setGraphKey(key);
        tracerText->position->setCoords(key, value);
        tracerText->setText(QString("Hora: %1\nVentas: %2").arg(int(key)).arg(int(value)));
        ui->widget->replot();
    }
}

void grafico::generarReportePDF(const QString &filePath) {
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMargins(60, 60, 60, 60));

    QCPPainter painter(&writer);

    // Título del reporte
    QFont titleFont = painter.font();
    titleFont.setPointSize(12);
    titleFont.setBold(true);
    painter.setFont(titleFont);
    painter.drawText(writer.width()/2 - 100, 50, "Reporte de Ventas por Hora");

    // Dibujar el gráfico en el PDF
    QRectF plotArea(100, 140, writer.width() - 160, writer.height() - 300);
    ui->widget->toPainter(&painter, plotArea.width(), plotArea.height());

    painter.end();

    QMessageBox::information(this, "Reporte Generado", "El reporte ha sido generado correctamente.");
}

void grafico::on_pushButton_clicked()
{
    QDate currentDate = QDate::currentDate();
    QString fecha = "Gráfico " + currentDate.toString("dd-MM-yyyy");
    QString filePath = QFileDialog::getSaveFileName(this, "Guardar Reporte", fecha, "*.pdf");
        if (!filePath.isEmpty()) {
            if (QFileInfo(filePath).suffix().isEmpty()) {
                filePath.append(".pdf");
            }
            generarReportePDF(filePath);
        }
}
