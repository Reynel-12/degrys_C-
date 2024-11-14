#include "invenoptimo.h"
#include "qlabel.h"
#include "qmovie.h"
#include "ui_invenoptimo.h"
#include "venta.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QStandardItemModel>
#include "serverconfig.h"

invenOptimo::invenOptimo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::invenOptimo)
{
    ui->setupUi(this);
    setWindowTitle("Inventario Optimo");

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

    ui->lvwInventarioOptimo->setStyleSheet(tableWidgetStyle);
    this->Abrir();
}

invenOptimo::~invenOptimo()
{
    delete ui;
}

void invenOptimo::Abrir()
{
    // Crear una animación de carga usando un archivo GIF
    QLabel *loadingLabel = new QLabel(this);
    QMovie *loadingMovie = new QMovie(":/Iconos/loading.gif");
    loadingLabel->setMovie(loadingMovie);
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingMovie->start();  // Iniciar la animación

    // Añadir la animación a la interfaz (puedes colocarlo en un layout si lo prefieres)
    ui->stackedWidget->addWidget(loadingLabel);  // Si tienes un stackedWidget o layout
    loadingLabel->show();

    // Deshabilitar la tabla para evitar interacciones mientras carga
    ui->lvwInventarioOptimo->setEnabled(false);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        // Ocultar la animación y detenerla cuando los datos lleguen
        loadingMovie->stop();
        loadingLabel->hide();

        // Rehabilitar la tabla para permitir interacciones
        ui->lvwInventarioOptimo->setEnabled(true);
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonArray inventario_optimo_array = json_doc.array();

            // Crear el modelo para la vista de tabla
            QStandardItemModel *standardModel = new QStandardItemModel(inventario_optimo_array.size(), 3, this);
            standardModel->setHorizontalHeaderLabels(QStringList() << "Código Producto" << "Nombre Producto" << "Tipo Producto" << "Inventario Óptimo");

            // Procesar los datos y llenar la tabla
            for (int i = 0; i < inventario_optimo_array.size(); ++i) {
                QJsonObject producto_obj = inventario_optimo_array[i].toObject();

                QString codigo_producto = producto_obj["codigo_producto"].toString();
                QString nombre_producto = producto_obj["nombre_producto"].toString();
                double inventario_optimo = producto_obj["inventario_optimo"].toDouble();
                QString unidad_producto = producto_obj["unidad_producto"].toString();

                // Llenar la tabla con los datos
                standardModel->setItem(i, 0, new QStandardItem(codigo_producto));        // Columna Código Producto
                standardModel->setItem(i, 1, new QStandardItem(nombre_producto));        // Columna Nombre Producto
                standardModel->setItem(i, 2, new QStandardItem(unidad_producto));
                standardModel->setItem(i, 3, new QStandardItem(QString::number(inventario_optimo)));  // Columna Inventario Óptimo
            }

            // Asignar el modelo a la vista de tabla
            ui->lvwInventarioOptimo->setModel(standardModel);
            ui->lvwInventarioOptimo->resizeColumnsToContents();
            ui->lvwInventarioOptimo->resizeRowsToContents();
            ui->lvwInventarioOptimo->setEditTriggers(QAbstractItemView::NoEditTriggers);

            // Limpieza
            reply->deleteLater();
        } else {
            qDebug() << "Error en la solicitud:" << reply->errorString();
        }
    });

    // Preparar la solicitud HTTP al backend para obtener el inventario óptimo
    QString ipAddress = serverConfig::instance().getIpAddress();
    Venta v = Venta(this);
    QNetworkRequest request(QUrl("http://" + v.IP + ":5000/inventario_optimo"));
    manager->get(request);
}

void invenOptimo::configurarEncabezados(QStandardItemModel *model)
{
    model->setHeaderData(0, Qt::Horizontal, "Codigo");
    model->setHeaderData(1, Qt::Horizontal, "Producto");
    model->setHeaderData(2, Qt::Horizontal, "Inventario optimo");
}
