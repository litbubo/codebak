#include "widget.h"

#include <QApplication>
#include <QLineEdit>
#include <QTextEdit>
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QLineEdit *LEdit = new QLineEdit("a line text",&w);
    QTextEdit *TEdit = new QTextEdit(&w);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(LEdit);
    layout->addWidget(TEdit);
    w.setLayout(layout);
    w.show();
    return a.exec();
}
