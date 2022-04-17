#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recvfile.h"

#include <QMessageBox>
#include <QTcpSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);


    connect(server, &QTcpServer::newConnection, this, [=]()
    {
        QTcpSocket *sock = server->nextPendingConnection();
        RecvFile *f = new RecvFile(sock, this);
        f->start();
        connect(f, &RecvFile::recv_over, [=]()
        {
            QMessageBox::information(this, "完成", "发送完成");
            f->quit();
            f->wait();
            f->deleteLater();
            sock->deleteLater();
        });
        QMessageBox::information(this, "连接", "连接成功");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    uint16_t port = ui->lineEdit->text().toUShort();
    server->listen(QHostAddress::Any, port);
}

