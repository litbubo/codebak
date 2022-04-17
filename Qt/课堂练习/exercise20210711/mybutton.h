#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = nullptr);

signals:
    void mySignal(int,  QString);
public slots:
    void myclick();


};

#endif // MYBUTTON_H
