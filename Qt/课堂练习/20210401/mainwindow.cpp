#include "mainwindow.h"

#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));
    //定义QAction
    openAction = new QAction(QIcon(":/img/Snipaste_2021-04-02_10-37-42.png"),
                                                         tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this,
                                                        &MainWindow::open);
    QMenu *file = menuBar()->addMenu(tr("&File"));
        file->addAction(openAction);
        //添加工具栏按钮
        QToolBar *toolBar = addToolBar(tr("&File"));
        toolBar->addAction(openAction);
        //设置状态栏信息
        QStatusBar *status = statusBar() ;
        status->addAction(openAction);
}

MainWindow::~MainWindow()
{}
void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
}


