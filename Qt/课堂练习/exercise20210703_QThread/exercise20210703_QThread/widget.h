#ifndef WIDGET_H
#define WIDGET_H
#include "mythread.h"
#include <QWidget>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    int num = 0;
    MyThread *myThread;

public slots:
    void Dealdone();

    void Stopthread();
};
#endif // WIDGET_H
