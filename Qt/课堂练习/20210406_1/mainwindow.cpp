#include "mainwindow.h"
#include "QFontDialog"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QFont font  = QFontDialog::getFont(&ok);
    if(ok)
    {
        ui->pushButton->setFont(font);

    }
}
