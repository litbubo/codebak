#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"
#include "Nixie.h"

int main()
{
    while(1)
    {
		Nixie(1,0);
		Nixie(2,1);
		Nixie(3,0);
		Nixie(4,3);
    }
    return 0;
}