/****************************************************************************
** Meta object code from reading C++ file 'grafico.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../grafico.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grafico.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_grafico_t {
    QByteArrayData data[6];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_grafico_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_grafico_t qt_meta_stringdata_grafico = {
    {
QT_MOC_LITERAL(0, 0, 7), // "grafico"
QT_MOC_LITERAL(1, 8, 16), // "actualizarTracer"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 39, 5), // "event"
QT_MOC_LITERAL(5, 45, 21) // "on_pushButton_clicked"

    },
    "grafico\0actualizarTracer\0\0QMouseEvent*\0"
    "event\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_grafico[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       5,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void grafico::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        grafico *_t = static_cast<grafico *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actualizarTracer((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject grafico::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_grafico.data,
      qt_meta_data_grafico,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *grafico::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *grafico::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_grafico.stringdata0))
        return static_cast<void*>(const_cast< grafico*>(this));
    return QDialog::qt_metacast(_clname);
}

int grafico::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
