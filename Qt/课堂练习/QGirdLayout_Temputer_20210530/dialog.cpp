#include "dialog.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QDial>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QPushButton *m_QuitButton = new QPushButton("Quit",this);
    QLabel *m_CenLabel = new QLabel("Centigrade",this);
    QLabel *m_FahLabel = new QLabel("Fahrenheit",this);
    m_FahLabel->setAlignment(Qt::AlignHCenter);
    QLabel *m_Label = new QLabel("0",this);
    QSlider *m_Slider = new QSlider(this);
    QLCDNumber *m_LCDNumber = new QLCDNumber(this);
    QDial *m_Dial = new QDial(this);
    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(10);
    layout->setMargin(20);
    //Quit按钮，起始于(0, 0)，横跨3个单元, 即colSpan=3
    layout->addWidget(m_QuitButton, 0, 0, 1, 3);
    //Centigrade标签，起于(1, 0)，横跨2个单元, 即colSpan=2
    layout->addWidget(m_CenLabel, 1, 0, 1, 2);
    //Fahrenheit标签，始于(1, 2)，占1个单元
    layout->addWidget(m_FahLabel, 1, 2);
    //“0”这个Label，起始于(2, 0)，纵越2个单元，rowSpan=2
    layout->addWidget(m_Label, 2, 0, 2, 1);
    //然后是Slider，起始于(2, 1)，纵越2个单元，rowSpan=2
    layout->addWidget(m_Slider, 2, 1, 2, 1);
    //LCDNumber起始于(2, 2)，占用一个单元
    layout->addWidget(m_LCDNumber, 2, 2);
    layout->addWidget(m_Dial, 3, 2);  //Dial表盘占用(3, 2)一个单元
    this->setLayout(layout);
}

Dialog::~Dialog()
{
}
