#include "mywidget.h"
#include "subwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    subWidget y;
    QWidget:: connect(&w,&myWidget::sendValue, &y, &subWidget::Function);
    w.setValue(500);
    //w.show();
    return a.exec();
}
