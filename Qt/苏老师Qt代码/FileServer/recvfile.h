#ifndef RECVFILE_H
#define RECVFILE_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
class RecvFile : public QThread
{
    Q_OBJECT
public:
    explicit RecvFile(QTcpSocket *sock ,QObject *parent = nullptr);

protected:
    void run() override;
signals:
    void recv_over();
private:
    QTcpSocket *sock;

};

#endif // RECVFILE_H
