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
	printf("请输入您所需运算的行列数:");
	scanf("%d",&numb);
	printf("请输入矩阵A的数字\n");
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
	printf("\n请输入矩阵B的数字\n");
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
	printf("结果为:\t\t");
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