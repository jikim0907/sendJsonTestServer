#include "interfacemanager.h"

interfacemanager* interfacemanager::mInstance = NULL;

interfacemanager *interfacemanager::getInstance()
{
    std::cout << "getinstance"<<mInstance <<std::endl;
    return mInstance;
}

interfacemanager::interfacemanager(QObject* parent)
    :QObject(parent)
{
    testServer = new server;
    if(!testServer->listen(QHostAddress::Any,5000)){
        qDebug() << "Server could not start!";
    }

    qDebug() << "Server started on port 5000!";
}
