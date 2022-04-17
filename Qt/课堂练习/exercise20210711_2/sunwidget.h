#ifndef SUNWIDGET_H
#define SUNWIDGET_H

#include <QWidget>
#include <QPushButton>

class sunWidget : public QWidget
{
    Q_OBJECT
public:
    explicit sunWidget(QWidget *parent = nullptr);

signals:
    void mySignal();
    void mySignal(int, QString);

public slots:
    void sendSlot();
private:
    QPushButton b;
};

#endif // SUNWIDGET_H
