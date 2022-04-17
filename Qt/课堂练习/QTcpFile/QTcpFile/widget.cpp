#include "widget.h"
#include "ui_widget.h"

#include <QHostAddress>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,8088);

    ui->pushButtonFIle->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);

    setWindowTitle("服务端口:8888");

    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
            {
                tcpSocket = tcpServer->nextPendingConnection();

                QString ip = tcpSocket->peerAddress().toString();
                quint16 port = tcpSocket->peerPort();

                QString str = QString("[%1:%2] 连接成功").arg(ip).arg(port);
                ui->textEdit->setText(str);

                ui->pushButtonFIle->setEnabled(true);
                /*ui->pushButtonSend->setEnabled(true);*/

                connect(tcpSocket, &QTcpSocket::readyRead,
                        [=]()
                        {
                            QByteArray buff = tcpSocket->readAll();
                            ui->textEdit->append(buff);
                        });
            });

    connect(&timer, &QTimer::timeout,
            [=]()
            {
                timer.stop();
                sendData();
            });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonFIle_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"open","../");

    if(filePath.isEmpty() == false)
    {
        fileName.clear();
        fileSize = 0;

        QFileInfo info(filePath);
        fileName = info.fileName();
        fileSize = info.size();

        qDebug() << "被发送给的文件实际名字" <<fileName;
        qDebug() << "被发送给的文件实际大小" <<fileSize;

        sendsize = 0;


        file = new QFile(this);
        file->setFileName(filePath);
        bool isok = file->open(QIODevice::ReadOnly);
        if(isok ==false)
        {
            qDebug() << "fail file";
        }

        ui->textEdit->append(filePath);
        ui->pushButtonFIle->setEnabled(false);
        ui->pushButtonSend->setEnabled(true);

    }
    else
    {
        qDebug() << "wrong";
    }
}

void Widget::on_pushButtonSend_clicked()
{
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);

    qint64 len = tcpSocket->write(head.toUtf8());

    if(len > 0)
    {
        timer.start(20);
    }
    else
    {
        qDebug() << "send head fail";
        file->close();
    }

    ui->pushButtonFIle->setEnabled(true);
    ui->pushButtonSend->setEnabled(false);
}

void Widget::sendData()
{
    qint64 len = 0;
    do
    {
        char buf[4*1024] = {0};

        len = 0;

        len = file->read(buf, sizeof (buf));

        len = tcpSocket->write(buf,len);

        sendsize += len;

    } while (len > 0);

    qDebug() << "发送的文件大小" <<sendsize;

    if (sendsize == fileSize)
    {
        ui->textEdit->append("send over");
        file->close();

        file = nullptr;

        /*
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
        */
    }
}
