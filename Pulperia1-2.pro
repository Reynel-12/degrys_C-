#-------------------------------------------------
#
# Project created by QtCreator 2024-03-10T16:01:25
#
#-------------------------------------------------

QT       += core gui sql network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pulperia1-2
TEMPLATE = app
CONFIG += console
QT += printsupport

SOURCES += main.cpp\
    invenoptimo.cpp \
    qcustomplot.cpp \
    serverconfig.cpp \
        venta.cpp \
    databaseproductos.cpp \
    vend.cpp \
    cantidad.cpp \
    vuelto.cpp \
    vendido.cpp \
    factura.cpp \
    agregarinventario.cpp \
    numinventario.cpp \
    contra.cpp \
    opcionproductos.cpp \
    nuevoproducto.cpp \
    modificarprod.cpp \
    modifi.cpp \
    cambiarnombre.cpp \
    cambiarunidad.cpp \
    cambiarprecio.cpp \
    eliminarproducto.cpp \
    numerofactura.cpp \
    nuevocod.cpp \
    grafico.cpp \
    descuento.cpp \
    clientes.cpp \
    seleccionarcliente.cpp \
    agregarnombre.cpp \
    montocliente.cpp \
    agregarprecio.cpp \
    agregartipo.cpp

HEADERS  += venta.h \
    databaseproductos.h \
    invenoptimo.h \
    qcustomplot.h \
    serverconfig.h \
    vend.h \
    cantidad.h \
    vuelto.h \
    vendido.h \
    factura.h \
    agregarinventario.h \
    numinventario.h \
    contra.h \
    opcionproductos.h \
    nuevoproducto.h \
    modificarprod.h \
    modifi.h \
    cambiarnombre.h \
    cambiarunidad.h \
    cambiarprecio.h \
    eliminarproducto.h \
    numerofactura.h \
    nuevocod.h \
    grafico.h \
    descuento.h \
    clientes.h \
    seleccionarcliente.h \
    agregarnombre.h \
    montocliente.h \
    agregarprecio.h \
    agregartipo.h

FORMS    += venta.ui \
    cantidad.ui \
    invenoptimo.ui \
    vuelto.ui \
    vendido.ui \
    agregarinventario.ui \
    numinventario.ui \
    contra.ui \
    opcionproductos.ui \
    nuevoproducto.ui \
    modificarprod.ui \
    modifi.ui \
    cambiarnombre.ui \
    cambiarunidad.ui \
    cambiarprecio.ui \
    eliminarproducto.ui \
    numerofactura.ui \
    nuevocod.ui \
    grafico.ui \
    descuento.ui \
    clientes.ui \
    seleccionarcliente.ui \
    agregarnombre.ui \
    montocliente.ui \
    agregarprecio.ui \
    agregartipo.ui

QMAKE_CXXFLAGS += -std=gnu++17
QMAKE_CXXFLAGS += -O2

RESOURCES += \
    iconos.qrc
