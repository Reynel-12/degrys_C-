#ifndef VENDIDO_H
#define VENDIDO_H

#include <QDialog>
#include "qstandarditemmodel.h"
#include "vend.h"
#include "factura.h"
#include <QTableWidget>

#include <QCloseEvent>
#include <QSqlDatabase>

namespace Ui {
class Vendido;
}

class QSqlTableModel;

class Vendido : public QDialog
{
    Q_OBJECT

public:
    explicit Vendido(QWidget *parent = 0);
    ~Vendido();
    //void establecerDatos(const QVector<Vend> &datos);
    void BuscarFacTablasVend(const QString &texto, QTableView* tablaProd, QTableWidget* tablaDestino);
    //void guardarDatos();
    //bool datosRepetidos(const QVector<Vend> &datos);
    void limpiar();
    //void guardarFacRepetida();
    //bool datosRepetidosFacRepetida(const QVector<Vend> &datos);
    //void verificarDatos();
    void crearPDF(QTableView *tableView, const QString &filePath);
    void ajustarAnchoQLineEdit(QLineEdit *lineEdit);
    void configurarEncabezados(QStandardItemModel *model);
    void onRowSelected(const QModelIndex &current);

private slots:
    void on_pushButton_clicked();
    void BuscarFac();
    void AbrirHistorial();
    void SeleccionProd();
    void SeleccionProdFac();
    void GenerarReporte();

    void filterTable(const QString &text);

    void on_pbtGrafico_clicked();

private:
    Ui::Vendido *ui;
    QVector<Vend> VN;
    QVector<Vend> VD;

    QVector<Factura> fac;

    QVector<Factura> CamCli;

    enum ColFac
    {
        FACTURA
    };

    enum colVend
    {
        NOFAC, PRODUCTO, TIPO, CANTIDAD, SUBTOTAL, TOTAL, CLIENTE, CAMBIO, FECHA, HORA, DESCUENTO, CAJA
    };

    QSqlTableModel *mModel;
    QSqlDatabase mDatabase;
};

#endif // VENDIDO_H
