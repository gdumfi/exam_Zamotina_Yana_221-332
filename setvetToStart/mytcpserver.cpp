#include "mytcpserver.h"

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status = 0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33332)) {
        qDebug() << "server is not started";
    } else {
        server_status = 1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    qDebug() << "client connected";
    if (server_status == 1) {
        QTcpSocket* curr_mTcpSocket = mTcpServer->nextPendingConnection();
        connect(curr_mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(curr_mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
        mTcpSocket.push_back(curr_mTcpSocket);
    }
}

void MyTcpServer::slotServerRead()
{
    QByteArray array;
    QTcpSocket* curr_mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    qDebug() << "То, что в сокете до отправки в массив: " << curr_mTcpSocket->peek(curr_mTcpSocket->bytesAvailable());

    if (curr_mTcpSocket->bytesAvailable() > 0) {
        array.clear();
        array = curr_mTcpSocket->readAll();
        qDebug() << "Массив после считывания из сокета: " << array;
        QString task = QString::fromUtf8(array);
        qDebug() << task;
        QByteArray response = parsing(task);
        qDebug() << response;
        curr_mTcpSocket->write(response);
        qDebug() << "Правильно: " << curr_mTcpSocket->peek(curr_mTcpSocket->bytesAvailable());
    }
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket* curr_mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    curr_mTcpSocket->close();
    curr_mTcpSocket->deleteLater();
}
