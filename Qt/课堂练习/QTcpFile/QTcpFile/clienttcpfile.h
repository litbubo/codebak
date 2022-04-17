#ifndef CLIENTTCPFILE_H
#define CLIENTTCPFILE_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class ClientTcpFile;
}

class ClientTcpFile : public QWidget
{
    Q_OBJECT

public:
    explicit ClientTcpFile(QWidget *parent = nullptr);
    ~ClientTcpFile();

private slots:
    void on_pushButtonCon_clicked();

private:
    Ui::ClientTcpFile *ui;
    QTcpSocket *tcpSocket = nullptr;
    QFile *file = nullptr;
    QString fileName;
    qint64 fileSize;
    qint64 recvSize;

    bool isStart;
};

#endif // CLIENTTCPFILE_H
