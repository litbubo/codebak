#include "login.h"
#include "mainwindow.h"
#include "find_form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    QObject::connect(&w, &Login::login_signal, []()
                        {
                            MainWindow *w2 = new MainWindow;
                            w2->show();
                        });
    QObject::connect(&w, &Login::find_signal, []()
                        {
                            Find_Form *w3 = new Find_Form;
                            w3->show();
                        });
    return a.exec();
}
