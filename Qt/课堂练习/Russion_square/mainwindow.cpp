#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *buttonleft = new QPushButton("左",this);
    buttonleft->move(200,500);
    buttonleft->resize(200,50);
    buttonleft->animateClick();
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
    painter.drawRect(X, Y, 110, 160);
}

void MainWindow::timerEvent(QTimerEvent *)
{
    Y += 2;
    repaint();
}



