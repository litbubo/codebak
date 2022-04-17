#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    QMenu *pFile = mBar->addMenu("file");
    QMenu *pEdit = mBar->addMenu("edit");
    QAction *pNEW = pFile->addAction("NEW");

    connect(pNEW, &QAction::triggered,
            []()
            {
                qDebug() << "button_new";
            }
    );
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("open");
    QToolBar *toolBar = addToolBar("toolBar");

    QPushButton *b = new QPushButton(this);
    b->setText("^_^");
    toolBar->addWidget(b);
}

MainWindow::~MainWindow()
{
}

