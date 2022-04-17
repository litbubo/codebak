#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutterfly.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/image/Red Butterfly.ico"));
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
    //setWindowState(Qt::WindowFullScreen);
    setAttribute(Qt::WA_TranslucentBackground);
    showMaximized();
    for(auto i = 0; i < 100; i ++)
    {
        MyButterFly *but = new MyButterFly(this);
        but->move(QRandomGenerator::global()->bounded(this->width()),
                  QRandomGenerator::global()->bounded(this->height()));
        but->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

