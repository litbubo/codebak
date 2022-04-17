#include "widget.h"

#include <QApplication>
#include <QLineEdit>
#include <QTextEdit>
#include <QLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QLineEdit *LEdit = new QLineEdit("a line text",  &w);
    QTextEdit *REdit = new QTextEdit(&w);
    // 将控件放入layout对象
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(LEdit);
    layout->addWidget(REdit);
    w.setLayout(layout);     // 设置窗体布局
    w.show();
    return a.exec();
}
