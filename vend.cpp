#include "vend.h"

Vend::Vend()
{
    this->Producto = "<Vacio>";
    this->Tipo = "<Vacio>";
    this->Cantidad = "<Vacio>";
    this->Precio = "<Vacio>";
    this->SubTotal = "<Vacio>";
    this->Total = "<Vacio>";
    this->Cliente = "<Vacio>";
    this->Cambio = "<Vacio>";
    this->Numero = "<Vacio>";
    this->NoFac = "<Vacio>";
    this->Fecha = "<Vacio>";
    this->Hora = "<Vacio>";
    this->Caja = "<Vacio>";
    this->Descuento = "0";
}

Vend::Vend(QString Producto, QString Tipo, QString Cantidad, QString Precio,
           QString SubTotal, QString Total, QString Cliente, QString Cambio,
           QString Numero, QString NoFac, QString Fecha, QString Hora, QString Caja,
           QString Descuento)
{
    this->Producto = Producto;
    this->Tipo = Tipo;
    this->Cantidad = Cantidad;
    this->Precio = Precio;
    this->SubTotal = SubTotal;
    this->Total = Total;
    this->Cliente = Cliente;
    this->Cambio = Cambio;
    this->Numero = Numero;
    this->NoFac = NoFac;
    this->Fecha = Fecha;
    this->Hora = Hora;
    this->Caja = Caja;
    this->Descuento = Descuento;
}

Vend::Vend(const Vend & Temp)
{
    this->Producto = Temp.Producto;
    this->Tipo = Temp.Tipo;
    this->Cantidad = Temp.Cantidad;
    this->Precio = Temp.Precio;
    this->SubTotal = Temp.SubTotal;
    this->Total = Temp.Total;
    this->Cliente = Temp.Cliente;
    this->Cambio = Temp.Cambio;
    this->Numero = Temp.Numero;
    this->NoFac = Temp.NoFac;
    this->Fecha = Temp.Fecha;
    this->Hora = Temp.Hora;
    this->Caja = Temp.Caja;
    this->Descuento = Temp.Descuento;
}
