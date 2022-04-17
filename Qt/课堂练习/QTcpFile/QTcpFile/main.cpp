#include "widget.h"
#include "clienttcpfile.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    ClientTcpFile w2;
    w2.show();
    return a.exec();
}
