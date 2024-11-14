#ifndef DATABASEPRODUCTOS_H
#define DATABASEPRODUCTOS_H

#pragma once
#include <QSqlDatabase>

class databaseproductos
{
public:
    //static databaseproductos& getInstance();
    bool openDatabase(QString *error = nullptr);
    databaseproductos(const QString &server,
                      const QString &driver,
                      const QString &user,
                      const QString &password,
                      const QString &databaseName,
                      bool trustedConnection = true);
    //~databaseproductos();
    QSqlDatabase getConexion();
    void closeConnection();

public:
    QSqlDatabase mDatabase;
    QString mServer;
    QString mDriver;
    QString mUser;
    QString mPassword;
    QString mDatabaseName;
    bool mTrustedConnection;
};

#endif // DATABASEPRODUCTOS_H
