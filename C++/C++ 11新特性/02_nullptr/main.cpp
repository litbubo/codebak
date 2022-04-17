#include <iostream>
#include "HelloWorld.h"
using namespace std;

void function(int a)
{
    std::cout << "int" << std::endl;
}

void function(char *a)
{
    std::cout << "char *" << std::endl;
}


int main(int argc, char **argv)
{
    //HelloWorld();
    NULL;
    function(0);
    function(nullptr);
    return 0;
}