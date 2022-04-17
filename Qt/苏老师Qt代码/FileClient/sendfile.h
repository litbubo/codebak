#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>

class SendFile : public QObject
{
    Q_OBJECT
public:
    explicit SendFile(QObject *parent = nullptr);
    void connect_working(QString ip, unsigned short port);
    void send_working(QString path);

signals:
    void connect_OK();
    void connect_Close();
    void progress(int percent);
private:
    QTcpSocket *sock;

};

#endif // SENDFILE_H
