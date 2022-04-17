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
    ui->lineEdit_ip->setText("127.0.0.1");
    tsocket = new QTcpSocket;

    connect(tsocket, &QTcpSocket::readyRead, this, [=]()
            {
                QByteArray data = tsocket->readAll();
                ui->textEdit_history->append("服务端say  " + data);
            });

    connect(tsocket, &QTcpSocket::disconnected, this, [=]()
            {
                ui->sendMessage->setDisabled(true);
                ui->tcpClose->setDisabled(true);
                ui->tcpStart->setDisabled(false);
                label->setPixmap(QPixmap(":/1").scaled(30,30));
                tsocket->close();
                //tsocket->deleteLater();
            });

    connect(tsocket, &QTcpSocket::connected, this, [=]()
            {
                ui->sendMessage->setDisabled(false);
                ui->tcpClose->setDisabled(false);
                ui->tcpStart->setDisabled(true);
                label->setPixmap(QPixmap(":/2").scaled(30,30));
            });

    label = new QLabel;
    label->setPixmap(QPixmap(":/1").scaled(30,30));
    ui->statusbar->addWidget(new QLabel("连接状态:   "));
    ui->statusbar->addWidget(label);
    ui->sendMessage->setDisabled(true);
    ui->tcpClose->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tcpStart_clicked()
{
    QString ip = ui->lineEdit_ip->text();
    uint16_t port = ui->lineEdit_port->text().toUShort();
    tsocket->connectToHost(QHostAddress(ip), port);
}


void MainWindow::on_sendMessage_clicked()
{
    QByteArray data = ui->textEdit_send->toPlainText().toUtf8();
    tsocket->write(data);
    ui->textEdit_history->append("客户端say  " + data);
}


void MainWindow::on_tcpClose_clicked()
{
    tsocket->close();
    //tsocket->deleteLater();
}

