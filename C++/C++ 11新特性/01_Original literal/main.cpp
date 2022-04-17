#include <iostream>
#include "HelloWorld.h"

using namespace std;
int main(int argc, char **argv)
{
    //HelloWorld();
    string str = "\Hello \Worl\d";
    cout << str << endl;
    string str1 = R"(\Hello \Worl\d)";
    cout << str1 << endl;
    //string str2 = R"(\Hello \Worl\d)xlp";
    //cout << str2 << endl;
    string str3 = R"(
    1111
    2222
    3333
    4444)";
    cout << str3 << endl;
    return 0;
}