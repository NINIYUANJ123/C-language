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
			printf("1��10W����������������Ϊ��%ld\n",i);
			count++;
		} 
	}
	printf("\n");
	printf("����������������%ld��\n",count);
	system("pause");
}
