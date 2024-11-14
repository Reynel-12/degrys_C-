#ifndef SERVERCONFIG_H
#define SERVERCONFIG_H
#include <QHostAddress>

class serverConfig
{
public:
    static serverConfig& instance() {
        static serverConfig instance;
        return instance;
    }

    void initializeIpAddress();
    QString getIpAddress() const;

private:
    serverConfig() = default;
    QString serverIpAddress;
};

#endif // SERVERCONFIG_H
