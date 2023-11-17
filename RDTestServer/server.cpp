#include "server.h"


serverthread::serverthread(qintptr socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{

}

server::server(QObject* parent) :QTcpServer(parent)
{

}

void serverthread::run() {

    QTcpSocket tcpSocket;
    if(!tcpSocket.setSocketDescriptor(socketDescriptor)){
        emit error(tcpSocket.error());
    }
    QFile loadFile(QStringLiteral("../RDTestServer/data/testpose.json"));
    qDebug() <<"Thread run!";
    QByteArray loadData = loadFile.readAll();//TO DO modified
    QJsonDocument loadDoc = QJsonDocument::fromJson(loadData);
    QByteArray jsonData = loadDoc.toJson();

    tcpSocket.write(jsonData);
    tcpSocket.waitForBytesWritten();
    tcpSocket.disconnectFromHost();
}

void server::incomingConnection(qintptr socketDescriptor) {
    serverthread* thread = new serverthread(socketDescriptor, this);
    qDebug()<<"incomingConnection called!";
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}


