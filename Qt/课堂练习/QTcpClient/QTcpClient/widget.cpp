#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                QByteArray temp = tcpSocket->readAll();
                ui->textEditread->append(temp);
            });
    connect(tcpSocket, &QTcpSocket::connected,
            [=]()
            {
                ui->textEditread->setText("connected");
            });
    connect(tcpSocket, &QTcpSocket::disconnected,
            [=]()
            {
                ui->textEditread->append("disconnected");
            });

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButtonconnect_clicked()
{
    QString ip = ui->lineEditip->text();

    qint16 port = ui->lineEdit8088->text().toInt();

    tcpSocket->connectToHost( QHostAddress(ip), port );

}

void Widget::on_pushButtonsend_clicked()
{
    QString str = ui->textEdit_4->toPlainText();
    tcpSocket->write( str.toUtf8().data() );
}

void Widget::on_pushButtonclose_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
