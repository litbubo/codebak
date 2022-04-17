#include "mainwindow.h"
#include <QSplitter>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
{
    //创建主分割窗口，设置为水平分割窗口(左右分割)
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);
    //创建一个QTextEdit控件 设置其父控件为mainSplitter
    QTextEdit *leftEdit = new QTextEdit(QObject::tr("左窗口"), mainSplitter);
    leftEdit->setAlignment(Qt::AlignCenter); //设QTextEdit文字居中
    //创建右侧上下分割窗口，设其父控件为mainSplitter
    QSplitter *rightSplitter=new QSplitter(Qt::Vertical, mainSplitter);
    //设置拖动时，只显示灰线。拖动到位后再显示分隔条
    rightSplitter->setOpaqueResize(false);
    //设置右侧分割的上下两个窗口内容
    QTextEdit *upEdit = new QTextEdit(QObject::tr("上窗口"), rightSplitter);
    upEdit->setAlignment(Qt::AlignCenter);
    QTextEdit *bottomEdit = new QTextEdit(QObject::tr("下窗口"), rightSplitter);
    bottomEdit->setAlignment(Qt::AlignCenter);
    //设置右部分割窗口为可伸缩控件
    mainSplitter->setStretchFactor(1, 1);
    mainSplitter->setWindowTitle(QObject::tr("分割窗口"));
    //将主分割设为中央部件
    setCentralWidget(mainSplitter);
    mainSplitter->show();
}

MainWindow::~MainWindow()
{
}

