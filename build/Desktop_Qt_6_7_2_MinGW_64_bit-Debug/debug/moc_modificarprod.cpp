/****************************************************************************
** Meta object code from reading C++ file 'modificarprod.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../modificarprod.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modificarprod.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSmodificarProdENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmodificarProdENDCLASS = QtMocHelpers::stringData(
    "modificarProd",
    "on_pbtCambiarCodigo_clicked",
    "",
    "on_pbtCambiarNombre_clicked",
    "on_pbtCambiarUnidad_clicked",
    "on_CambiarPrecio_clicked",
    "on_pbtSalir_clicked",
    "onCambiarCodigoClicked",
    "onCambiarNombreClicked",
    "onCambiarUnidadClicked",
    "onCambiarPrecioClicked",
    "onEliminarProductoClicked",
    "on_pbtEliminarProd_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmodificarProdENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

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

Q_CONSTINIT const QMetaObject modificarProd::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSmodificarProdENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmodificarProdENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmodificarProdENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<modificarProd, std::true_type>,
        // method 'on_pbtCambiarCodigo_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbtCambiarNombre_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbtCambiarUnidad_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CambiarPrecio_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbtSalir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCambiarCodigoClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCambiarNombreClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCambiarUnidadClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCambiarPrecioClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEliminarProductoClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbtEliminarProd_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void modificarProd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<modificarProd *>(_o);
        (void)_t;
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
    (void)_a;
}

const QMetaObject *modificarProd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modificarProd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmodificarProdENDCLASS.stringdata0))
        return static_cast<void*>(this);
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
