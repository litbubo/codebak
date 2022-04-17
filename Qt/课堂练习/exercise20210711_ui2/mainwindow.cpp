#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    //connect(ui->spin, &QSpinBox::valueChanged, ui->slider, &QSlider::setValue);
    connect(ui->slider, SIGNAL(valuechange(int)),
            ui->spin, SLOT(setValue(int)));

}

