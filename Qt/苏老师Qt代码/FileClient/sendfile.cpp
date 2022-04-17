#include "sendfile.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QHostAddress>

SendFile::SendFile(QObject *parent) : QObject(parent)
{
    sock = new QTcpSocket(this);

    connect(sock, &QTcpSocket::connected, this, &SendFile::connect_OK);
    connect(sock, &QTcpSocket::disconnected, this, [=]()
    {
        sock->close();
    });
    connect(sock, &QTcpSocket::disconnected, this, &SendFile::connect_Close);
}

void SendFile::connect_working(QString ip, unsigned short port)
{
    sock->connectToHost(QHostAddress(ip), port);
    qDebug() << "连接";
}

void SendFile::send_working(QString path)
{
    static quint64 total = 0;
    qDebug() << path;
    QFile f(path);
    QFileInfo info(f);
    quint64 size = info.size();
    qDebug() << size;
    f.open(QIODevice::ReadOnly);
    while (f.atEnd() == false)
    {
        if(total == 0)
            sock->write((char *)&size, 8);
        QByteArray line = f.readLine();
        sock->write(line);
        total += line.size();
        //qDebug() << (total / (double)size) * 100;
        emit progress((total / (double)size) * 100);
    }
    total = 0;
}
