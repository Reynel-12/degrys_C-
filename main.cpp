#include "venta.h"
#include <QApplication>
#include <QStyleFactory>
#include "serverconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Venta w;
    a.setStyle("fusion");
    // Inicializar la dirección IP
    serverConfig::instance().initializeIpAddress();

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    palette.setColor(QPalette::WindowText, Qt::black);
    a.setPalette(palette);

    w.setWindowIcon(QIcon(":/Iconos/Tienda.png"));
    w.showMaximized();
    //w.show();

    return a.exec();
}
