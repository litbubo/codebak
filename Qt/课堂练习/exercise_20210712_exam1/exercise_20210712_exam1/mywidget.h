#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class myWidget : public QWidget
{
    Q_OBJECT
signals:
    void sendValue(int);

private:
    int m_value;
public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
    void setValue(int);
};
#endif // MYWIDGET_H
