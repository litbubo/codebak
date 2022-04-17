#include "clienttcpfile.h"
#include "ui_clienttcpfile.h"
#include <QMessageBox>
#include <QHostAddress>
#include <QDebug>

ClientTcpFile::ClientTcpFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientTcpFile)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    isStart = true;

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                QByteArray buf = tcpSocket->readAll();

                if(true == isStart)
                {
                    isStart = false;

                    /*
                     *QString str = "hello##1024";
                     *str.section("##",0,0);
                     */

                    fileName = QString(buf).section("##",0,0);
                    fileSize = QString(buf).section("##",1,1).toInt();
                    recvSize = 0;

                    qDebug() << "收到的大小" << fileSize;
                    qDebug() << "收到的文件" << fileName;

                    file = new QFile(this);
                    file->setFileName(fileName);

                    bool isOk = file->open(QIODevice::WriteOnly);

                    if (isOk == false)
                    {
                        qDebug() << "文件写入失败";
                    }

                }
                else
                {
                    qint64 len = file->write(buf);
                    if(len > 0)
                        recvSize += len;

                    /*
                     *qDebug() << "收到的len" << len;
                     *qDebug() << "收到的数据" << recvSize;
                     */
                    len = 0;

                    if(recvSize == fileSize)
                    {
                        file->close();

                        QMessageBox::information(this,"完成","接收完成");
                        tcpSocket->write("file done");

                        file = nullptr;

                       /*
                        *tcpSocket->disconnectFromHost();
                        *tcpSocket->close();
                        */
                        isStart = true;

                    }
                }
            });
}

ClientTcpFile::~ClientTcpFile()
{
    delete ui;
}

void ClientTcpFile::on_pushButtonCon_clicked()
{
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip),port);
}
