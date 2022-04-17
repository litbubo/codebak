#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>

class subWidget : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget(QWidget *parent = nullptr);

signals:

public slots:
    void Function(int);

};

#endif // SUBWIDGET_H
