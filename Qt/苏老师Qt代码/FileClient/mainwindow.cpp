#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sendfile.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTcpSocket>
#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->send->setDisabled(true);
    ui->ip->setText("127.0.0.1");
    ui->port->setText("8888");
    ui->progressBar->setValue(0);
    ui->progressBar->setRange(0, 100);

    SendFile *s = new SendFile;
    t = new QThread(this);
    s->moveToThread(t);

    connect(this, &MainWindow::connect_info, s, &SendFile::connect_working);
    connect(this, &MainWindow::file_info, s, &SendFile::send_working);
    connect(s, &SendFile::connect_OK, this, [=]()
    {
        QMessageBox::information(this, "连接", "连接成功");
        ui->send->setDisabled(false);
    });
    connect(s, &SendFile::connect_Close, this, [=]()
            {
                t->quit();
                t->wait();
                ui->connect->setDisabled(false);
                ui->choose->setDisabled(false);
                ui->send->setDisabled(true);
            });

    connect(s, &SendFile::progress, ui->progressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connect_clicked()
{
    t->start();

    QString ip = ui->ip->text();
    unsigned short port = ui->port->text().toUShort();
    emit connect_info(ip, port);
    ui->connect->setDisabled(true);
}


void MainWindow::on_choose_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "选择文件", "C:\\Users\\imxlp\\Desktop\\");
    if(path.isEmpty())
    {
        QMessageBox::warning(this, "文件", "文件不能为空");
        return;
    }
    ui->filePath->setText(path);
}


void MainWindow::on_send_clicked()
{
    emit file_info(ui->filePath->text());
}

