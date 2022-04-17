#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>

class Director : public QObject
{
    Q_OBJECT
signals:
    void Teach(int nNewVal);
public:
    explicit Director(QObject *parent = nullptr);
    void Talk(int nNewVal);
private:
    int m_Value;
signals:

};

#endif // DIRECTOR_H
