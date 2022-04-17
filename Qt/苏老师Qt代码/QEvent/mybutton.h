#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPixmap>
#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
signals:

private:
    QPixmap m_pix;

};

#endif // MYBUTTON_H
