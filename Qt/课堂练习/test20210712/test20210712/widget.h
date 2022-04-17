#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
protected:
    void timerEvent(QTimerEvent *e);
    void paintEvent(QPaintEvent *e);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    int id = 0;
    int id2 = 0;
    int sec= 0;
    int sec2 = 0;
    QLabel *l;
    QLabel *l2;
    int x = 0;
};
#endif // WIDGET_H
