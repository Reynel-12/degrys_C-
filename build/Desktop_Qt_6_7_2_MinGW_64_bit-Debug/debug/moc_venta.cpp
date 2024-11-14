/****************************************************************************
** Meta object code from reading C++ file 'venta.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../venta.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'venta.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVentaENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVentaENDCLASS = QtMocHelpers::stringData(
    "Venta",
    "Abrir",
    "",
    "Anadir",
    "Limpiar",
    "Vender",
    "Historial",
    "ImprimeFac",
    "BuscarEnTabla",
    "texto",
    "QTableView*",
    "tabla",
    "BuscarCodProd",
    "RecibirCambioCliente",
    "QList<Factura>",
    "datos",
    "anadirInventario",
    "Iniciar",
    "Apagar",
    "NuevaConexion",
    "RecibiendoMensajes",
    "ClienteDesconectado",
    "clientId",
    "QTcpSocket*",
    "socket",
    "GenerarReporte",
    "AgregarDescuento",
    "VerClientes",
    "Mas",
    "on_EliminarProd_clicked",
    "actualizarTotal",
    "subtotalFila",
    "resetBarcodeData",
    "on_pbtBorrarProdCaja1_clicked",
    "on_pbtBorrarProdCaja2_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVentaENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  158,    2, 0x0a,    1 /* Public */,
       3,    0,  159,    2, 0x0a,    2 /* Public */,
       4,    0,  160,    2, 0x0a,    3 /* Public */,
       5,    0,  161,    2, 0x0a,    4 /* Public */,
       6,    0,  162,    2, 0x0a,    5 /* Public */,
       7,    0,  163,    2, 0x0a,    6 /* Public */,
       8,    2,  164,    2, 0x0a,    7 /* Public */,
      12,    0,  169,    2, 0x0a,   10 /* Public */,
      13,    1,  170,    2, 0x0a,   11 /* Public */,
      16,    0,  173,    2, 0x0a,   13 /* Public */,
      17,    0,  174,    2, 0x0a,   14 /* Public */,
      18,    0,  175,    2, 0x0a,   15 /* Public */,
      19,    0,  176,    2, 0x0a,   16 /* Public */,
      20,    0,  177,    2, 0x0a,   17 /* Public */,
      21,    2,  178,    2, 0x0a,   18 /* Public */,
      25,    0,  183,    2, 0x0a,   21 /* Public */,
      26,    0,  184,    2, 0x0a,   22 /* Public */,
      27,    0,  185,    2, 0x0a,   23 /* Public */,
      28,    0,  186,    2, 0x0a,   24 /* Public */,
      29,    0,  187,    2, 0x08,   25 /* Private */,
      30,    1,  188,    2, 0x08,   26 /* Private */,
      32,    0,  191,    2, 0x08,   28 /* Private */,
      33,    0,  192,    2, 0x08,   29 /* Private */,
      34,    0,  193,    2, 0x08,   30 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 23,   22,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Venta::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSVentaENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVentaENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVentaENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Venta, std::true_type>,
        // method 'Abrir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Anadir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Limpiar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Vender'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Historial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ImprimeFac'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BuscarEnTabla'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableView *, std::false_type>,
        // method 'BuscarCodProd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RecibirCambioCliente'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<Factura> &, std::false_type>,
        // method 'anadirInventario'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Iniciar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Apagar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NuevaConexion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RecibiendoMensajes'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'ClienteDesconectado'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        // method 'GenerarReporte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AgregarDescuento'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'VerClientes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Mas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EliminarProd_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualizarTotal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'resetBarcodeData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbtBorrarProdCaja1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbtBorrarProdCaja2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Venta::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Venta *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Abrir(); break;
        case 1: _t->Anadir(); break;
        case 2: _t->Limpiar(); break;
        case 3: _t->Vender(); break;
        case 4: _t->Historial(); break;
        case 5: _t->ImprimeFac(); break;
        case 6: _t->BuscarEnTabla((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTableView*>>(_a[2]))); break;
        case 7: _t->BuscarCodProd(); break;
        case 8: _t->RecibirCambioCliente((*reinterpret_cast< std::add_pointer_t<QList<Factura>>>(_a[1]))); break;
        case 9: _t->anadirInventario(); break;
        case 10: _t->Iniciar(); break;
        case 11: _t->Apagar(); break;
        case 12: _t->NuevaConexion(); break;
        case 13: { QString _r = _t->RecibiendoMensajes();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->ClienteDesconectado((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[2]))); break;
        case 15: _t->GenerarReporte(); break;
        case 16: _t->AgregarDescuento(); break;
        case 17: _t->VerClientes(); break;
        case 18: _t->Mas(); break;
        case 19: _t->on_EliminarProd_clicked(); break;
        case 20: _t->actualizarTotal((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 21: _t->resetBarcodeData(); break;
        case 22: _t->on_pbtBorrarProdCaja1_clicked(); break;
        case 23: _t->on_pbtBorrarProdCaja2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTableView* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Venta::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Venta::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVentaENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Venta::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_WARNING_POP
