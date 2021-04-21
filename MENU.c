#include <stdio.h>
#include "STD_TYPES.h"
u8 menu (void)
{
	u8 x=0;
	
	printf("To add new patient record press 1\n");
	printf("To edit  patient record press 2\n");
	printf("To reserve a slot with the doctor press 3\n");
	printf("To cancel reservation press 4\n");
	printf("To end program press 0\n");
	scanf("%d",&x);
	if (x>4)
	{
		printf("wrong choice ,try again\n");
		menu();
	}
	return x;
}