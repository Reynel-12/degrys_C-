#ifndef VUELTO_H
#define VUELTO_H

#include <QDialog>
#include <QVector>
#include "venta.h"
#include "databaseproductos.h"
//#include "vendido.h"

namespace Ui {
class Vuelto;
}

class Vuelto : public QDialog
{
    Q_OBJECT

public:
    explicit Vuelto(QWidget *parent = nullptr);
    ~Vuelto();
    void setDatosCompartidos(const QString &datos);

public slots:
    //void actualizarCambioDesdeSpinbox(int nuevoValor);

    //void agregarValor(int valor);

    void restarNumeros();
    int Cambio() const;
    int Cliente() const;
    int Total() const;

private slots:
    void on_btbConfir_accepted();

    void on_btbConfir_rejected();

private:
    //QSqlDatabase mDatabase;
    QSqlDatabase m_db;
    Ui::Vuelto *ui;
    Venta *venta;
    QVector<Vend> vend;

    QVector<Factura> Fac;
};

#endif // VUELTO_H
