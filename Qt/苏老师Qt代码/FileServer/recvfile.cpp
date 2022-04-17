#include "recvfile.h"

#include <QFile>

RecvFile::RecvFile(QTcpSocket* sock , QObject *parent) : QThread(parent)
{
    this->sock = sock;
}

void RecvFile::run()
{
    QFile *f = new QFile("recv.mp4");
    f->open(QIODevice::WriteOnly);

    connect(sock, &QTcpSocket::readyRead, [=]()
    {
        static quint64 count = 0;
        static quint64 total = 0;
        if(count == 0)
        {
            sock->read((char *)&total, 8);
        }
        QByteArray all = sock->readAll();
        count += all.size();
        f->write(all);
        if(count == total)
        {
            sock->close();
            f->close();
            f->deleteLater();
            emit recv_over();
            count = 0;
            total = 0;
        }
        //qDebug() << "count" << count << "total" << total;
    });

    this->exec();

}
