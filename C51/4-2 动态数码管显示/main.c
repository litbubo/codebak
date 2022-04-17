#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "Delayms.h"
#include "Nixie.h"

int main()
{
    while(1)
    {
        /*add your codes*/
		Nixie(1,1);
		//Delayms(5);
		Nixie(2,2);
		//Delayms(5);
		Nixie(3,3);
		//Delayms(5);
    }
    return 0;
}