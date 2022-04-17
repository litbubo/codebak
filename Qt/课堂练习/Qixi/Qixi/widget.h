#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QCloseEvent>
#include "mainwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
signals:
    void closeOpen();

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer *myTimer = nullptr;
    MainWidget *mainWidget = nullptr;
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event);

public   slots:
    void dealTimer();
};
#endif // WIDGET_H
