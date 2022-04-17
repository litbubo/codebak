#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    tcpSocket=new QTcpSocket(this);

    connect(tcpSocket,SIGNAL(connected()),
            this,SLOT(dataTransfer()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress("192.168.77.133"),4000);
}

void MainWindow::dataTransfer()
{
    tcpSocket->write(ui->lineEdit->text().toLatin1());
}
