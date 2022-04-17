#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("dialog");
    QAction *action = menu->addAction("exexdialog");
    connect(action, &QAction::triggered,
            []()
            {
                QDialog dlg;
                dlg.exec();
            });
}

MainWindow::~MainWindow()
{
}

