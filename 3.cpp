#include <stdio.h>
#include <math.h>
#include "stdlib.h"
main()
{
	long int i,x,y,z,count = 0;
	for(i = 0;i < 100000;i++)
	{
		x = sqrt(i + 100);
		y = sqrt(i + 268);
		if((x * x == i + 100)&&(y * y == i + 268))
		{
			printf("1到10W以内满足条件的数为：%ld\n",i);
			count++;
		} 
	}
	printf("\n");
	printf("满足条件的数共有%ld个\n",count);
	system("pause");
}
