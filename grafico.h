#ifndef GRAFICO_H
#define GRAFICO_H

#include "qdatetime.h"
#include <QDialog>
#include <qcustomplot.h>

namespace Ui {
class grafico;
}

struct Facturas{
    int id;
    QString producto;
    QString categoria;
    int cantidad;
    double precioUnitario;
    double total;
    double descuento;
    double totalFinal;
    QDateTime fechaHora;
    QString caja;
};

class grafico : public QDialog
{
    Q_OBJECT

public:
    explicit grafico(QWidget *parent = 0);
    ~grafico();
    void verGrafico();

    QVector<Facturas> leerHistorial(const QString& archivo);
    QMap<QString, int> ventasPorCaja(const QVector<Facturas>& facturas);
    QMap<QString, int> ventasPorProducto(const QVector<Facturas>& facturas);
    QMap<int, QSet<int>> ventasPorHora(const QVector<Facturas>& facturas);
    void crearGraficoVentasPorHora(const QMap<int, QSet<int>>& ventasPorHora);

    void generarReportePDF(const QString &filePath);

private slots:
    void actualizarTracer(QMouseEvent *event);

    void on_pushButton_clicked();

private:
    Ui::grafico *ui;

    QCPItemTracer *tracer;
    QCPItemText *tracerText;
};

#endif // GRAFICO_H
