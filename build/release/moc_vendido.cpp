/****************************************************************************
** Meta object code from reading C++ file 'vendido.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../vendido.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vendido.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Vendido_t {
    QByteArrayData data[11];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Vendido_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Vendido_t qt_meta_stringdata_Vendido = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Vendido"
QT_MOC_LITERAL(1, 8, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "BuscarFac"
QT_MOC_LITERAL(4, 41, 14), // "AbrirHistorial"
QT_MOC_LITERAL(5, 56, 13), // "SeleccionProd"
QT_MOC_LITERAL(6, 70, 16), // "SeleccionProdFac"
QT_MOC_LITERAL(7, 87, 14), // "GenerarReporte"
QT_MOC_LITERAL(8, 102, 11), // "filterTable"
QT_MOC_LITERAL(9, 114, 4), // "text"
QT_MOC_LITERAL(10, 119, 21) // "on_pbtGrafico_clicked"

    },
    "Vendido\0on_pushButton_clicked\0\0BuscarFac\0"
    "AbrirHistorial\0SeleccionProd\0"
    "SeleccionProdFac\0GenerarReporte\0"
    "filterTable\0text\0on_pbtGrafico_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vendido[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void Vendido::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Vendido *_t = static_cast<Vendido *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->BuscarFac(); break;
        case 2: _t->AbrirHistorial(); break;
        case 3: _t->SeleccionProd(); break;
        case 4: _t->SeleccionProdFac(); break;
        case 5: _t->GenerarReporte(); break;
        case 6: _t->filterTable((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pbtGrafico_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Vendido::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Vendido.data,
      qt_meta_data_Vendido,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Vendido::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vendido::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Vendido.stringdata0))
        return static_cast<void*>(const_cast< Vendido*>(this));
    return QDialog::qt_metacast(_clname);
}

int Vendido::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
