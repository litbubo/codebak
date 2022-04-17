#include <STC89C5xRC.H>
#include "Delayms.h"

unsigned char Key()
{
	unsigned char KeyNumber = 0;
	
	if(P31 == 0)
	{
		Delayms(20);
		while(P31 == 0)
			;
		Delayms(20);
		KeyNumber = 1;
	}
	
	if(P30 == 0)
	{
		Delayms(20);
		while(P30 == 0)
			;
		Delayms(20);
		KeyNumber = 2;
	}
	
	if(P32 == 0)
	{
		Delayms(20);
		while(P32 == 0)
			;
		Delayms(20);
		KeyNumber = 3;
	}
	
	if(P33 == 0)
	{
		Delayms(20);
		while(P33 == 0)
			;
		Delayms(20);
		KeyNumber = 4;
	}
	
	return KeyNumber;
}