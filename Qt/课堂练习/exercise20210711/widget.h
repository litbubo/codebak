#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "mybutton.h"

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void mySlots(int,  QString);
    void mySlots();
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    myButton *p = nullptr;
};
#endif // WIDGET_H
