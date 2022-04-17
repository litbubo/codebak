#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
    this->resize(381,509);
    ui->label->setText("<center>loading</center>");
    myTimer->start(500);

    connect(myTimer, SIGNAL(timeout()), this, SLOT(dealTimer()));

    connect(this, &Widget::closeOpen,
            [=]()
            {
                mainWidget = new MainWidget;
                mainWidget->showFullScreen();
            }
            );
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{

    QPainter p;  //创建画家对象
    p.begin(this); //指定当前窗口为绘图设备

    //绘图操作
    //画背景图
    p.drawPixmap(0,0,width(),height(), QPixmap("../Image/spflash.gif"));
    p.end();
}

void Widget::closeEvent(QCloseEvent *event)
{
    emit closeOpen();
}

void Widget::dealTimer()
{
    static int i = 0;
    static int j = 0;
    if (i == 0)
        ui->label->setText("<center>loading</center>");
    else if(i == 1)
        ui->label->setText("<center>loading.</center>");
    else if(i == 2)
        ui->label->setText("<center>loading. .</center>");
    else
        ui->label->setText("<center>loading. . .</center>");
    i++;
    i %= 4;
    if(j++ == 11)
        this->close();
}
