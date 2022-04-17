#include "director.h"

Director::Director(QObject *parent) : QObject(parent)
{
    m_Value = 1;
}

void Director::Talk(int nNewVal)
{
    emit Teach(nNewVal);
}
