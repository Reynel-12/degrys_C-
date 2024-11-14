#ifndef MODIFICARPROD_H
#define MODIFICARPROD_H

#include <QDialog>

namespace Ui {
class modificarProd;
}

class modificarProd : public QDialog
{
    Q_OBJECT

public:
    explicit modificarProd(QWidget *parent = 0);
    ~modificarProd();

    QString opcionActual() const;

private slots:
    void on_pbtCambiarCodigo_clicked();

    void on_pbtCambiarNombre_clicked();

    void on_pbtCambiarUnidad_clicked();

    void on_CambiarPrecio_clicked();

    void on_pbtSalir_clicked();

    void onCambiarCodigoClicked();
    void onCambiarNombreClicked();
    void onCambiarUnidadClicked();
    void onCambiarPrecioClicked();
    void onEliminarProductoClicked();

    void on_pbtEliminarProd_clicked();

private:
    Ui::modificarProd *ui;

    QString opcion;
};

#endif // MODIFICARPROD_H
