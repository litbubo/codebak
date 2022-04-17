#ifndef MYBUTTERFLY_H
#define MYBUTTERFLY_H

#include <QPixmap>
#include <QPoint>
#include <QWidget>

class MyButterFly : public QWidget
{
    Q_OBJECT
public:
    explicit MyButterFly(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
private:
    QPixmap m_pix;
    int select = 0;
    QPoint pox;
signals:

};

#endif // MYBUTTERFLY_H
