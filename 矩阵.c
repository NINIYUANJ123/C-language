#include "stdio.h"
#include "stdlib.h"
main()
{
	int i,j,k,hang,lie,count,numb,a[100][100],b[100][100],c[100][100];
	numb=0;
	count=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
			c[i][j]=0;
	}
	printf("�����������������������:");
	scanf("%d",&numb);
	printf("���������A������\n");
	for(i=0;i<numb;i++)
	{
		for(j=0;j<numb;j++)
		{
			scanf("%d",&a[i][j]);
			count++;
			if(count%numb==0)
				printf("\n");
		}
	}
	printf("\n���������B������\n");
	for(i=0;i<numb;i++)
	{
		for(j=0;j<numb;j++)
		{
			scanf("%d",&b[i][j]);
			count++;
			if(count%numb==0)
				printf("\n");
		}
	}

	for(i=0;i<numb;i++)
	{
		for(j=0;j<numb;j++)
		{
			for(k=0;k<numb;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("���Ϊ:\t\t");
	for(i=0;i<numb;i++)
	{
		for(j=0;j<numb;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n\t\t");
	}
	system("pause");
	return 0;
}