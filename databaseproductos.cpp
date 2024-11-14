#include "databaseproductos.h"
#include "QDebug"
#include <QSqlQuery>
#include <QSqlError>
#include "vuelto.h"

databaseproductos::databaseproductos(const QString &server,
                                     const QString &driver,
                                     const QString &user,
                                     const QString &password,
                                     const QString &databaseName,
                                     bool trustedConnection)
{
    mDatabase = QSqlDatabase::addDatabase("QODBC");
    mServer = server;
    mDriver = driver;
    mUser = user;
    mPassword = password;
    mDatabaseName =databaseName;
    mTrustedConnection = trustedConnection;
}

bool databaseproductos::openDatabase(QString *error)
{
    //Acceder a base de datos
    mDatabase.setDatabaseName(QString("DRIVER={%1};SERVER=%2;DATABASE=%3;UID=%4;PWD=%5;Trusted_Connection=%6")
                              .arg(mDriver)
                              .arg(mServer)
                              .arg(mDatabaseName)
                              .arg(mUser)
                              .arg(mPassword)
                              .arg(mTrustedConnection ? "Yes" : "No"));
    if (!mDatabase.open()){
        if (error != nullptr){
            *error = mDatabase.lastError().text();
        }
        return false;
    }
    return true;
}

QSqlDatabase databaseproductos::getConexion()
{
    return mDatabase;
}

void databaseproductos::closeConnection()
{
    return mDatabase.close();
}
