#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList str;
    str <<"无";
    ui->comboBox_2->addItems(str);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(80);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    int x = ui->progressBar->value();
    x++;
    if(x>=100) x=0;
    ui->progressBar->setValue(x);
}

void MainWindow::on_pushButton_3_clicked()
{
    this->startTimer(100);

}
