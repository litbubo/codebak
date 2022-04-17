#ifndef WIDGETLOGIN_H
#define WIDGETLOGIN_H
#include "widgetmain.h"
#include <QWidget>
namespace Ui {
class widgetlogin;
}

class widgetlogin : public QWidget
{
    Q_OBJECT

public:
    explicit widgetlogin(QWidget *parent = nullptr);
    ~widgetlogin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::widgetlogin *ui;
};

#endif // WIDGETLOGIN_H
