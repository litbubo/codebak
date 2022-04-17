#ifndef WIDGETJION_H
#define WIDGETJION_H

#include <QWidget>

namespace Ui {
class widgetjion;
}

class widgetjion : public QWidget
{
    Q_OBJECT

public:
    explicit widgetjion(QWidget *parent = nullptr);
    ~widgetjion();

private:
    Ui::widgetjion *ui;
};

#endif // WIDGETJION_H
