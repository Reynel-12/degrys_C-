#include "serverconfig.h"
#include <QNetworkInterface>

void serverConfig::initializeIpAddress() {
    foreach (const QNetworkInterface &networkInterface, QNetworkInterface::allInterfaces()) {
            // Verificar si la interfaz de red está activa y no es de loopback
            if (networkInterface.flags() & QNetworkInterface::IsUp && !(networkInterface.flags() & QNetworkInterface::IsLoopBack)) {
                qDebug() << "Interface:" << networkInterface.humanReadableName(); // Mostrar el nombre de la interfaz
                foreach (const QHostAddress &address, networkInterface.allAddresses()) {
                    qDebug() << "Address:" << address.toString(); // Mostrar todas las direcciones IP
                    if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)) {
                        // Filtrar solo las direcciones IP válidas en la red
                        serverIpAddress = address.toString();
                        qDebug() << "Selected IP address:" << serverIpAddress;
                        return; // Salir después de encontrar la primera IP válida
                    }
                }
            }
        }
        // Si no se encuentra una IP válida, podrías asignar un valor por defecto o manejar el error
        serverIpAddress = QString(); // Dejar vacío si no se encuentra ninguna IP
}

QString serverConfig::getIpAddress() const {
    return serverIpAddress;
}
