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
    QSlider *slider = new QSlider(Qt::Horizontal,&w);
    spinBox->setValue(35);
    slider->setValue(50);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    w.setLayout(layout);
    w.show();
    return a.exec();
}
