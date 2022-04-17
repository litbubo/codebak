#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H
#include "widgetjion.h"
#include <QWidget>

namespace Ui {
class widgetmain;
}

class widgetmain : public QWidget
{
    Q_OBJECT

public:
    explicit widgetmain(QWidget *parent = nullptr);
    ~widgetmain();

private slots:
    void on_pushButton_clicked();

private:
    Ui::widgetmain *ui;
};

#endif // WIDGETMAIN_H
