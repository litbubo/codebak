#ifndef WIDGET_H
#define WIDGET_H
#include "mythread.h"
#include <QWidget>
#include <QThread>
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
    void dealSignal();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    MyThread *myT;
    QThread  *mythread;
signals:
    void startThread();
};
#endif // WIDGET_H
