#include <QCoreApplication>
#include <QObject>
#include "director.h"
#include "student.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Director t1;
    Student s1;
    QObject::connect(&t1, &Director::Teach ,&s1, &Student::Learn);
    t1.Talk(42);
    return a.exec();
}
