#include "mywidget.h"


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    l = new QLabel(this);
    s = new QSlider(Qt::Horizontal,this);
    p = new QPushButton("^_^",this);
    l->move(10,50);
    s->move(50,50);
    l->resize(30,30);
    s->resize(200,30);
    s->setMaximum(200);
    s->setMinimum(0);
    s->setValue(50);
    l->setText("50");
    connect(s,SIGNAL(valueChanged(int)),this,SLOT(setLabelText(int)));
    connect(p,&QPushButton::clicked,this,&myWidget::addSilder);
    connect(this, &myWidget::addSliderValue, s,&QSlider::setValue);
    this->resize(800,800);


    com =new QComboBox(this);
    com->setGeometry(20,100,100,30);
    com->addItem("www");
    com->addItem("xxx");


    /*  currentTextChanged(const QString &text)
     *connect(com,&QComboBox::currentIndexChanged, this, &myWidget::setTextMess);
     *connect(com,&QComboBox::currentIndexChanged,
     *       [](const QString &text)
     *       {
     *           //QMessageBox::question(this,"xiaoxi",text,QMessageBox::Ok);
     *       });
     */
    connect(com, &QComboBox::currentIndexChanged, this, &myWidget::setonChanged);


    list = new QListWidget(this);
    l2 = new QLabel(this);
    list->move(380,0);
    l2->move(300,0);
    l2->setFixedWidth(70);
    list->addItem(new QListWidgetItem("1"));
    list->addItem(new QListWidgetItem("2"));
    list->addItem(new QListWidgetItem("3"));
    list->addItem(new QListWidgetItem("4"));
    list->addItem(new QListWidgetItem("5"));

    connect(list, &QListWidget::currentTextChanged,
            [=](const QString &currentText)
            {
                l2->setText(currentText);
            });

    //currentTextChanged(const QString &currentText)

}

myWidget::~myWidget()
{
}

void myWidget::setLabelText(int x)
{
    l->setText(QString("%1").arg(x));
}

void myWidget::addSilder()
{
    int x = s->value();
    x++;
    emit addSliderValue(x);
}

void myWidget::setTextMess(const QString &text)
{
    QMessageBox::question(this,"xiaoxi",text,QMessageBox::Ok);
}

void myWidget::setonChanged(int index)
{
    QMessageBox::question(this,"xiaoxi",com-> itemText(index) ,QMessageBox::Ok);
}
