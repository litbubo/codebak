#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any, 8088);

    setWindowTitle("服务端");

    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
            {
                tcpSocket = tcpServer->nextPendingConnection();

                QString ip = tcpSocket->peerAddress().toString();

                qint16 port = tcpSocket->peerPort();

                QString temp = QString("[%1:%2]:连接成功").arg(ip).arg(port);

                ui->textEdit->setText(temp);

                connect(tcpSocket, &QTcpSocket::readyRead,
                        [=]()
                        {
                            //从通信套接字中取出内容
                            QByteArray array = tcpSocket->readAll();
                            ui->textEdit_2->append(array);
                        });
            });

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_sendbutton_clicked()
{

}


void Widget::on_closebutton_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = nullptr;
}
