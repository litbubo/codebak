#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>



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

void MainWindow::closeEvent(QCloseEvent *e)
{
    auto ret = QMessageBox::question(this, "close", "close the windows");
    qDebug() << ret ;
    if(ret == QMessageBox::Yes)
    {
        e->accept();
    }
    else
    {
        e->ignore();
    }

}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    qDebug() << "old size" << e->oldSize() << "    new size" << e->size();
}

