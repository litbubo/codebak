#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"

#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QBrush>
#include <QRect>
#include <QPixmap>
#include <QPainter>
#include <QInputDialog>
#include <QStringList>
#include <QProgressDialog>
#include <QPushButton>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->setTimerType(Qt::VeryCoarseTimer);
    this->setWindowIcon(QIcon(":/image/m1.png"));

    connect(ui->pushButton, &QPushButton::clicked, timer, [=]()
    {
        if(timer->isActive() == false)
        {
            timer->start(1000);
        }
        else
        {
            qDebug() << "log";
        }
    });

    connect(timer, &QTimer::timeout, ui->label, [=]()
    {
        QTime tt = QTime::currentTime();
        ui->label->setText(tt.toString("hh:mm:ss.zzz"));
    });

    this->setWindowTitle("test");
    //this->setFixedSize(QSize(700,700));

    connect(this, &MainWindow::windowTitleChanged, this, [](const QString &title)
    {
        qDebug() << "标题改变为：" << title;
    });
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &MainWindow::customContextMenuRequested, this,[](const QPoint &pos)
    {
        QMenu menu;
        menu.addAction("1");
        menu.addAction("2");
        menu.addAction("3");
        menu.addAction("4");
        menu.exec(QCursor::pos());
    });

    ui->action->setIcon(QIcon(":/image/m3.png"));
    QPushButton *btn = new QPushButton("测试");
    //ui->toolBar->addWidget(btn);
    connect(btn, &QPushButton::clicked, [=]()
    {
        QMessageBox::information(this, "测试", "这是一个测试窗口");
    });

    connect(ui->action, &QAction::triggered, [=]()
    {
        QMessageBox::information(this, "action", "this is a action");
    });

    ui->statusbar->showMessage("6666666", 3000);
    QPushButton *btn2 = new QPushButton("测试2");
    QToolBar *bar = new QToolBar("工具栏");
    bar->addAction(ui->action);
    bar->addWidget(btn2);
    this->addToolBar(Qt::RightToolBarArea, bar);
    ui->statusbar->addWidget(btn);
    QTimer::singleShot(5000, this, [=]()
    {
        btn->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    QRect r = this->frameGeometry();
    this->move(r.topLeft() + QPoint(10,20));

}


void MainWindow::on_pushButton_3_clicked()
{
    QRect r = this->frameGeometry();
    qDebug() << "左上角" << r.topLeft()
                << "右上角" << r.topRight()
                   << "左下角" << r.bottomLeft()
                      << "右下角" << r.bottomRight();
}


void MainWindow::on_pushButton_5_clicked()
{
    this->setWindowTitle("36666010");
}


void MainWindow::on_pushButton_6_clicked()
{
    myDialog d;
    int ret = d.exec();
    qDebug() << ret ;
}


void MainWindow::on_pushButton_7_clicked()
{
    QMessageBox::about(this, "myQMessageBox", "这是一个窗口");
    QMessageBox::critical(this, "myerror", "这是一个错误窗口");
    auto ret = QMessageBox::question(this, "myquestion", "您想要保存吗", QMessageBox::Save|QMessageBox::Cancel, QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
    {
        QMessageBox::information(this, "myinformation", "保存");
    }
    else
    {
        QMessageBox::information(this, "myinformation", "取消");
    }

}


void MainWindow::on_pushButton_8_clicked()
{
#define SAVE
#ifdef GET
    auto ret = QFileDialog::getExistingDirectory(this, "myget", R"(D:\)", QFileDialog::ShowDirsOnly);
    QMessageBox::information(this, "getExistingDirectory", ret);
#endif
#ifdef OPEN
    auto str = QString("Text files (*.txt *.cpp)");
    auto ret = QFileDialog::getOpenFileName(this, "myopen", R"(D:\)","Images (*.png *.xpm *.jpg);;Text files (*.txt *.cpp);;XML files (*.xml)", &str, QFileDialog::ShowDirsOnly) ;
    QMessageBox::information(this, "getOpenFileName", ret);
#endif
#ifdef OPENS
    auto str = QString("Text files (*.txt *.cpp)");
    auto ret = QFileDialog::getOpenFileNames(this, "myopen", R"(D:\)","Images (*.png *.xpm *.jpg);;Text files (*.txt *.cpp);;XML files (*.xml)", &str, QFileDialog::ShowDirsOnly) ;
    QString temp;
    for(const auto &i: qAsConst(ret))
    {
        temp += i;
        temp += "\n";
    }
    QMessageBox::information(this, "getOpenFileName", temp);
#endif
#ifdef SAVE
    auto str = QString("Text files (*.txt)");
    auto ret = QFileDialog::getSaveFileName(this, "保存", R"(D:\)","Images (*.png *.xpm *.jpg);;Text files (*.txt *.cpp);;XML files (*.xml)", &str, QFileDialog::ShowDirsOnly) ;
    QMessageBox::information(this, "getOpenFileName", ret);
#endif

}


void MainWindow::on_pushButton_9_clicked()
{
    bool ok;
    //QFont ret = QFontDialog::getFont(&ok, QFont("楷体", 20), this, "设置字体" );
    //qDebug() << "ok value id " << ok;
    QFont ret = QFontDialog::getFont(NULL);
    ui->label_2->setFont(ret);
}


void MainWindow::on_pushButton_10_clicked()
{
    QColor color = QColorDialog::getColor();
    QBrush b(color);
    QRect r(0, 0, ui->label_Rect->width(), ui->label_Rect->height());
    QPixmap pix(r.width(), r.height());
    QPainter p(&pix);
    p.fillRect(r, b);
    ui->label_4->setText(QString("red = %1;  green = %2; blue = %3").arg(color.red()).arg(color.green()).arg(color.blue()));
    ui->label_Rect->setPixmap(pix);
}


void MainWindow::on_pushButton_11_clicked()
{
#define MULTITEXT
#ifdef INT
    bool ok;
    auto ret = QInputDialog::getInt(this, "整型数", "输入整型数", 10, 0, 200, 2, &ok);
    if(ok)
        QMessageBox::information(this, "Int", QString::number(ret));
#endif

#ifdef DOUBLE
    bool ok;
    auto ret = QInputDialog::getDouble(this, "浮点数", "输入浮点数", 1000, 1000, 20000, 2, &ok);
    if(ok)
        QMessageBox::information(this, "Double", QString::number(ret));
#endif

#ifdef ITEM
    QStringList item;
    item << "qqq" << "rrr" << "eee" << "rrr" << "ttt" ;
    bool ok;
    auto ret = QInputDialog::getItem(this, "浮点数", "输入浮点数", item, 1, false, &ok);
    if(ok)
        QMessageBox::information(this, "Double", ret);
#endif

#ifdef TEXT
    bool ok;
    auto ret = QInputDialog::getText(this, "密码", "请输入密码", QLineEdit::Password, "123456", &ok);
    if(ok)
        QMessageBox::information(this, "密码", ret);
#endif

#ifdef MULTITEXT
    bool ok;
    auto ret = QInputDialog::getMultiLineText(this, "文本", "请输入文本", "123456", &ok);
    if(ok)
        QMessageBox::information(this, "文本", ret);
#endif
}


void MainWindow::on_pushButton_12_clicked()
{
    QProgressDialog *d = new QProgressDialog("正在拷贝", "取消操作", 0, 100, this);
    d->setWindowTitle("我的拷贝");
    d->setWindowModality(Qt::WindowModal);
    d->show();
    static int i = 0;
    QTimer *t = new QTimer(this);
    connect(t, &QTimer::timeout, [=]()
    {
        i++;
        d->setValue(i);
        if(i >= 100)
        {
            i = 0;
            t->stop();
            delete d;
            delete t;
        }
    });
    t->start(100);
    connect(d, &QProgressDialog::canceled, [=]()
    {
        i = 0;
        t->stop();
        delete d;
        delete t;
    });
    //qDebug() << i ;
}

