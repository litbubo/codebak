#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mybutton.h"

class Widget : public QWidget
{
    Q_OBJECT

    //QPushButton *b1 = new QPushButton(this);
    myButton *b1 = new myButton(this);

    myButton *b2 = new myButton(b1);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
