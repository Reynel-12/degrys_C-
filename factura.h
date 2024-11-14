#ifndef FACTURA_H
#define FACTURA_H
#include <QString>


class Factura
{
public:
    Factura();
    Factura(const Factura&);
    Factura(QString, QString, QString, QString);
public:
    QString NoFac;
    QString Cliente;
    QString Cambio;
    QString Total;
};

#endif // FACTURA_H
