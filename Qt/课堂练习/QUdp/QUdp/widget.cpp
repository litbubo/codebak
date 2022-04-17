#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    //udpSocket->bind(8088);

    udpSocket->bind(QHostAddress::AnyIPv4,8088);

    udpSocket->joinMulticastGroup(QHostAddress("224.0.0.2"));

    //udpSocket->leaveMulticastGroup();

    this->setWindowTitle("端口8088");

    connect(udpSocket, &QUdpSocket::readyRead,
            [=]()
            {
                QHostAddress address;
                quint16 port;
                char buf[1024] = {0};
                qint64 len = udpSocket->readDatagram(buf, sizeof (buf), &address, &port);
                if (len > 0)
                {
                    QString str = QString("[%1:%2] %3")
                            .arg(address.toString())
                            .arg(port)
                            .arg(buf);
                    ui->textEdit->setText(str);
                }
            });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonsend_clicked()
{
    QString ip = ui->lineEditip->text();
    qint16 port = ui->lineEditport->text().toInt();

    QString str = ui->textEdit->toPlainText();

    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);
}
