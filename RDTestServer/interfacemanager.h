#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

#include "server.h"

class interfacemanager : public QObject
{
    Q_OBJECT
    public:
    interfacemanager(QObject* parent = nullptr);
    static interfacemanager *getInstance();
    static interfacemanager *mInstance;

    server* testServer;
};

#endif // INTERFACEMANAGER_H
