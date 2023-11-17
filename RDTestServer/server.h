#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <iostream>


class serverthread : public QThread
{
    Q_OBJECT
    public:
        serverthread(qintptr socketDescriptor, QObject *parent);
        void run() override;
    signals:
        void error(QTcpSocket::SocketError socketError);

    private:
        qintptr socketDescriptor;
};


class server : public QTcpServer
{
    Q_OBJECT
    public:
        server(QObject* parent = nullptr);
    protected:
        void incomingConnection(qintptr socketDescriptor) override;
};

#endif // SERVER_H
