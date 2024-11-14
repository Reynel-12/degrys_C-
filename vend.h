#ifndef VEND_H
#define VEND_H
#include <QString>

class Vend
{
public:
    Vend();
    Vend(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
    Vend(const Vend &);
public:
    QString Producto;
    QString Tipo;
    QString Cantidad;
    QString Precio;
    QString SubTotal;
    QString Total;
    QString Cliente;
    QString Cambio;
    QString Numero;
    QString NoFac;
    QString Fecha;
    QString Hora;
    QString Caja;
    QString Descuento;
};

#endif // VEND_H
