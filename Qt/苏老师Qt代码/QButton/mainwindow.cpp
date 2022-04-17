#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QMenu>
#include <QMenu>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setIcon(QIcon(":/image/m1.png"));
    ui->pushButton->setIconSize(QSize(40,40));
    connect(ui->pushButton, &QPushButton::clicked, this, [=]()
    {
        qDebug() << "我是一个普通按钮" ;
    });

    ui->checkBtn->setCheckable(true);
    connect(ui->checkBtn, &QPushButton::toggled, this, [=](bool b)
    {
        qDebug() << "我是一个Check按钮，当前状态：" << b;
    });

    QMenu *m = new QMenu;
    QAction *a1 = m->addAction("111");
    QAction *a2 = m->addAction("222");
    QAction *a3 = m->addAction("333");
    QAction *a4 = m->addAction("444");
    connect(a1, &QAction::triggered, this, []()
    {
        qDebug() << "111";
    });
    connect(a2, &QAction::triggered, this, []()
    {
        qDebug() << "222";
    });
    connect(a3, &QAction::triggered, this, []()
    {
        qDebug() << "333";
    });
    ui->pushButton->setMenu(m);

    ui->toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButton->setIcon(QIcon(":/image/m1.png"));
    ui->toolButton->setIconSize(QSize(40,40));
    connect(ui->toolButton, &QToolButton::clicked, this, [=]()
    {
        qDebug() << "我是一个普通按钮" ;
    });

    ui->toolButton_check->setCheckable(true);
    connect(ui->toolButton_check, &QToolButton::toggled, this, [=](bool b)
    {
        qDebug() << "我是一个Check按钮，当前状态：" << b;
    });

    ui->toolButton_menu->setMenu(m);
    //ui->toolButton_menu->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolButton_menu->setPopupMode(QToolButton::InstantPopup);
    connect(ui->toolButton_menu, &QToolButton::clicked, this, []()
    {
        qDebug() << "this is tool";
    });

    ui->toolButton_action->setIconSize(QSize(40,40));
    ui->toolButton_action->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QAction *act = new QAction(QIcon(":/image/m2.png"), "test");
    ui->toolButton_action->setDefaultAction(act);
    connect(ui->toolButton_action, &QToolButton::triggered, this, [=](QAction* act)
    {
        act->setText("changed");
        act->setIcon(QIcon(":/image/m3.png"));
    });

    ui->toolButton_arrow->setText("向上");
    ui->toolButton_arrow->setArrowType(Qt::UpArrow);
    ui->toolButton_arrow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->checkBox_all->setTristate(true);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::check_deal);
    connect(ui->checkBox_2, &QCheckBox::stateChanged, this, &MainWindow::check_deal);
    connect(ui->checkBox_3, &QCheckBox::stateChanged, this, &MainWindow::check_deal);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn996_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        qDebug() << "no 996";
    }
    else
    {
        qDebug() << "996还行";
    }
}


void MainWindow::on_nomoney_stateChanged(int arg1)
{

}


void MainWindow::on_nogirl_stateChanged(int arg1)
{

}

void MainWindow::check_deal(int check)
{
    if(check == Qt::Checked)
    {
        num ++;
    }
    else
    {
        num--;
    }

    if(num == 3)
    {
        ui->checkBox_all->setCheckState(Qt::Checked);
    }
    else if(num == 0)
    {
        ui->checkBox_all->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->checkBox_all->setCheckState(Qt::PartiallyChecked);
    }
}



void MainWindow::on_checkBox_all_clicked(bool checked)
{
    if (checked)
    {
        ui->checkBox->setCheckState(Qt::Checked);
        ui->checkBox_2->setCheckState(Qt::Checked);
        ui->checkBox_3->setCheckState(Qt::Checked);

    }
    else
    {
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->checkBox_2->setCheckState(Qt::Unchecked);
        ui->checkBox_3->setCheckState(Qt::Unchecked);
    }
}

