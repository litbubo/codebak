#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->move(209,152);
    this->resize(537,456);

    connect(ui->pushButton, &QPushButton::clicked,
            [=]()
            {
                QString str =  ui->textEdit->toPlainText();
                qDebug() << str;
                ui->listWidget->addItem(new QListWidgetItem(str));
            }
            );
}

Widget::~Widget()
{
    delete ui;
}

