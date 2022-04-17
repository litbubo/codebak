#include <QCoreApplication>
#include <iostream>
class Mystring
{
private:
    char *pString;
    int m_Size;
public:
    Mystring(const char *str)
    {
        this->pString = new char[strlen(str) + 1];
        strcpy(pString, str);
        m_Size = strlen(str);
    }

    friend std::ostream & operator <<(std::ostream &cout, Mystring &obj);

};

std::ostream & operator <<(std::ostream &cout, Mystring &obj)
{
    cout << "字符串的长度" << obj.m_Size;
    cout << "字符串的内容" << obj.pString;
    return cout;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mystring str1("Hello World");
    std::cout << str1;

    return a.exec();
}
