#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QEvent>

#include <QMouseEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event);
    //void mouse
    void mouseMoveEvent(QMouseEvent *event);

signals:

};

#endif // MYLABEL_H
