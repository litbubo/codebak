#include "widget.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("55555");
    QPushButton b;
    b.setText("^_^");
    b.setParent(&w);
    b.move(200,300);
    w.show();
    return a.exec();
}
