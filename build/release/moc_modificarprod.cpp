/****************************************************************************
** Meta object code from reading C++ file 'modificarprod.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../modificarprod.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modificarprod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_modificarProd_t {
    QByteArrayData data[13];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modificarProd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modificarProd_t qt_meta_stringdata_modificarProd = {
    {
QT_MOC_LITERAL(0, 0, 13), // "modificarProd"
QT_MOC_LITERAL(1, 14, 27), // "on_pbtCambiarCodigo_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 27), // "on_pbtCambiarNombre_clicked"
QT_MOC_LITERAL(4, 71, 27), // "on_pbtCambiarUnidad_clicked"
QT_MOC_LITERAL(5, 99, 24), // "on_CambiarPrecio_clicked"
QT_MOC_LITERAL(6, 124, 19), // "on_pbtSalir_clicked"
QT_MOC_LITERAL(7, 144, 22), // "onCambiarCodigoClicked"
QT_MOC_LITERAL(8, 167, 22), // "onCambiarNombreClicked"
QT_MOC_LITERAL(9, 190, 22), // "onCambiarUnidadClicked"
QT_MOC_LITERAL(10, 213, 22), // "onCambiarPrecioClicked"
QT_MOC_LITERAL(11, 236, 25), // "onEliminarProductoClicked"
QT_MOC_LITERAL(12, 262, 26) // "on_pbtEliminarProd_clicked"

    },
    "modificarProd\0on_pbtCambiarCodigo_clicked\0"
    "\0on_pbtCambiarNombre_clicked\0"
    "on_pbtCambiarUnidad_clicked\0"
    "on_CambiarPrecio_clicked\0on_pbtSalir_clicked\0"
    "onCambiarCodigoClicked\0onCambiarNombreClicked\0"
    "onCambiarUnidadClicked\0onCambiarPrecioClicked\0"
    "onEliminarProductoClicked\0"
    "on_pbtEliminarProd_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modificarProd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void modificarProd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modificarProd *_t = static_cast<modificarProd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pbtCambiarCodigo_clicked(); break;
        case 1: _t->on_pbtCambiarNombre_clicked(); break;
        case 2: _t->on_pbtCambiarUnidad_clicked(); break;
        case 3: _t->on_CambiarPrecio_clicked(); break;
        case 4: _t->on_pbtSalir_clicked(); break;
        case 5: _t->onCambiarCodigoClicked(); break;
        case 6: _t->onCambiarNombreClicked(); break;
        case 7: _t->onCambiarUnidadClicked(); break;
        case 8: _t->onCambiarPrecioClicked(); break;
        case 9: _t->onEliminarProductoClicked(); break;
        case 10: _t->on_pbtEliminarProd_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject modificarProd::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_modificarProd.data,
      qt_meta_data_modificarProd,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *modificarProd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modificarProd::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_modificarProd.stringdata0))
        return static_cast<void*>(const_cast< modificarProd*>(this));
    return QDialog::qt_metacast(_clname);
}

int modificarProd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
