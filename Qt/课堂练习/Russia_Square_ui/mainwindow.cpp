#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(600,900);
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);	   //设置蓝色画笔
    QBrush brush;   //画刷。填充几何图形的调色板，由颜色和填充风格组成
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(X, Y, width, height);
    if(Y > 600 - height)
    {
        Y = 0;
        X = random()%(600 - width);
    }
    painter.setPen(Qt::gray);
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(0, 600, 600, 300);
}

void MainWindow::timerEvent(QTimerEvent *)
{
    Y += 2;
    repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (t)
    {
        timerId = startTimer(10);
    }
    else
    {
        killTimer(timerId);
    }
    t = 1-t;
}

void MainWindow::on_pushButton_3_clicked()
{
    if(X + 20 <= 600 - width)
        X += 20;
    else if(X + 20 > 600 -width)
        X = 600 - width;
}

void MainWindow::on_pushButton_clicked()
{
    if(X -20 >=0)
        X -= 20;
    else if(X - 20 < 0)
        X = 0;
}

void MainWindow::on_pushButton_5_clicked()
{
    Y = 600 - height;
}

void MainWindow::on_pushButton_4_clicked()
{
    int temp;
    temp = width;
    width = height;
    height = temp;
}
