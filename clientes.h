#ifndef CLIENTES_H
#define CLIENTES_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class clientes;
}

class QSqlQueryModel;

class clientes : public QDialog
{
    Q_OBJECT

public:
    explicit clientes(QWidget *parent = 0);
    ~clientes();

    void verClientes();
    bool actualizarTotalCliente(const QString &codigo, int monto);
    bool insertarPago(const QString &codigo, int monto);
    int obtenerTotalCliente(const QString &codigo);
    void eliminarDatosCliente(const QString &codigo);
    bool eliminarRegistros(const QString &tabla, const QString &codigo);
    bool obtenerDatosCliente(const QString& codigoCliente, QTableView *productosView, QTableView *pagosView, int& totalCliente);
    bool ejecutarConsulta(const QString& consulta, QSqlQueryModel *model, int codigoCliente);
    void conectarSeleccionFila();
    void actualizarDetallesProducto(const QModelIndex &current, const QModelIndex &);
    void onRowSelected(const QModelIndex &current);

public slots:
    void CancelarMonto();
    void Confirmar();

private:
    Ui::clientes *ui;

    QSqlQueryModel *mModel;
};

#endif // CLIENTES_H
