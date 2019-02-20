#include "stdio.h"
#include "stdlib.h"
main()
{
	int i,j,k,c=0;
	for (i=1;i<5;i++)
	{
		for (j=1;j<5;j++)
		{
			for (k=1;k<5;k++)
			{
				if(k!=i && k!=j && i!=j)
				{
					c+=1;
					printf("%d%d%d\n",i,j,k);
				}
			}
		}
	}
	printf("\n¹²ÓÐ%d¸ö\n\n",c);
	system("pause");
}