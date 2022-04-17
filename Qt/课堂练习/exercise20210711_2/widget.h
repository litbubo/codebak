#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

#include "sunwidget.h"

class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void mySlot();
    void changeWin();
    void dealSub();
    //void dealSlot(int, QString);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QPushButton b1;
    QPushButton *b2 = nullptr;
    QPushButton b3;

    sunWidget sunWin;

};
#endif // WIDGET_H
