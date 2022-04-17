#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void closeEvent(QCloseEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);


private:
    Ui::Widget *ui;
    int sec = 0;
    int sec0 = 0;
    int id1 = 0;
    int id2 = 0;
};
#endif // WIDGET_H
