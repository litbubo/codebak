#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_port->setText("8888");
    tserver = new QTcpServer(this);

    connect(tserver, &QTcpServer::newConnection, this, [=]()
    {
        tsocket = tserver->nextPendingConnection();
        connect(tsocket, &QTcpSocket::readyRead, this, [=]()
                {
                    QByteArray data = tsocket->readAll();
                    ui->textEdit_history->append("客户端say  " + data);
                });
        ui->sendMessage->setDisabled(false);
        label->setPixmap(QPixmap(":/2").scaled(30,30));

        connect(tsocket, &QTcpSocket::disconnected, this, [=]()
                {
                    ui->sendMessage->setDisabled(true);
                    label->setPixmap(QPixmap(":/1").scaled(30,30));
                    tsocket->close();
                    tsocket->deleteLater();
                });
    });

    label = new QLabel;
    label->setPixmap(QPixmap(":/1").scaled(30,30));
    ui->statusbar->addWidget(new QLabel("连接状态:   "));
    ui->statusbar->addWidget(label);
    ui->sendMessage->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tcpStart_clicked()
{
    uint16_t port = ui->lineEdit_port->text().toUShort();
    tserver->listen(QHostAddress::Any, port);
    ui->tcpStart->setDisabled(true);
}


void MainWindow::on_sendMessage_clicked()
{
    QByteArray data = ui->textEdit_send->toPlainText().toUtf8();
    tsocket->write(data);
    ui->textEdit_history->append("服务端say  " + data);
}

