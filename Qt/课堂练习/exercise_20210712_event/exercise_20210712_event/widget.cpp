#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::close);
    id1 = startTimer(100);
    id2 = startTimer(1000);
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "close";
    //QMessageBox *mess = new QMessageBox(this,"question","shifouguanbi");
    int x = QMessageBox::question(this,"question","shifouguanbi");
    if (x == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
    //mess->exec();
    //event->accept();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
    {
        ui->pushButton->setText(QString("%1").arg(sec0++));
        if (sec0 == 80)
        killTimer(id1);
    }
    else if(event->timerId() == id2)
    {
        ui->label->setText(QString("%1").arg(sec++));
        if (sec == 5)
            killTimer(id2);
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
        qDebug() << "Qt::key_A";
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setColor(Qt::blue);
    QBrush b;
    b.setColor(Qt::red);
    b.setStyle(Qt::DiagCrossPattern);
    p.setPen(pen);
    p.setBrush(b);
    p.drawRect(50,50,500,700);
}

