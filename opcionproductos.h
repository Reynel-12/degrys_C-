#ifndef OPCIONPRODUCTOS_H
#define OPCIONPRODUCTOS_H

#include <QDialog>

namespace Ui {
class opcionProductos;
}

class opcionProductos : public QDialog
{
    Q_OBJECT

public:
    explicit opcionProductos(QWidget *parent = 0);
    ~opcionProductos();

    QString opcionProd() const;

private slots:
    void on_pbtAgInventario_clicked();

    void on_btnAgNuevoProd_clicked();

    void on_btnModificarProd_clicked();

    void on_pushButton_clicked();

    void onAgregarInventarioClicked();
    void onAgregarNuevoProductoClicked();
    void onModificarProductoClicked();
    void onBorrarFacturaClicked();
    void onNumeroFacturaClicked();
    void onAgregarClienteClicked();

    void on_pbtBorrarFac_clicked();

    void on_pbtNumFac_clicked();

    void on_pbtAgregarCliente_clicked();

private:
    Ui::opcionProductos *ui;

    QString opcionActual;
};

#endif // OPCIONPRODUCTOS_H
