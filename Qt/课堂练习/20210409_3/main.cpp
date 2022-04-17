#include "widget.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QSpinBox *spinBox = new QSpinBox(&w);
    QSlider *slider = new QSlider(Qt::Horizontal, &w);
    spinBox->setValue(35);
    slider->setValue(50);
    //创建布局对象，将控件加入其中
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    w.setLayout(layout);	//在窗体上设置layout
    w.show();
    return a.exec();
}
