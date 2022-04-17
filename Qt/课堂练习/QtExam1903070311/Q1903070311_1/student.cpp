#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::Learn(int nNewVal)
{
    qDebug() << "学习到" << nNewVal;
}
