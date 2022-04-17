#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString ("Win32磁盘映像工具"));
    w.show();
    return a.exec();
}
