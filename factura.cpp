#include "factura.h"

Factura::Factura()
{
    this->NoFac = "Vacio";
    this->Cambio = "Vacio";
    this->Cliente = "Vacio";
    this->Total = "Vacio";
}

Factura::Factura(QString NoFac, QString Cambio, QString Cliente, QString Total)
{
    this->NoFac = NoFac;
    this->Cambio = Cambio;
    this->Cliente = Cliente;
    this->Total = Total;
}

Factura::Factura(const Factura& temp)
{
    this->NoFac = temp.NoFac;
    this->Cambio = temp.Cambio;
    this->Cliente = temp.Cliente;
    this->Total = temp.Total;
}
