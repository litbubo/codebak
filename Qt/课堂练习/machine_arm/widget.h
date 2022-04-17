#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QObject>

class Widget : public QWidget
{
    Q_OBJECT
    int angel = 0;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
};
#endif // WIDGET_H
