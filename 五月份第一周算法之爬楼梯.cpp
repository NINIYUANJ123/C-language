#include "stdio.h"
#include "stdlib.h"
int flag,numb[100];
void Compare();
main()
{
	printf("请输入默认的能力消耗值(以-1终止):");
	for(int i = 0;i<100;i++)
	{
		scanf("%d",&numb[i]);
		if(numb[i] == -1)
			break;
	}
	Compare();
	system("pause");
}
void Find()
{
	int p[2][2],Min;
	p[0][0]=numb[0]+numb[1];
	p[0][1]=numb[0]+numb[2];
	p[1][0]=numb[1]+numb[2];
	p[1][1]=numb[1]+numb[3];
	Min=p[0][0];
	for(int i=0;i<2;i++)
		for(int j=0;i<2;i++)
		{
			if(Min<p[i][j])
			{
				Min = p[i][j];
				flag=i;
			}
		}
}
void Compare()
{
	int power=numb[flag];
	while(numb[flag+1] || numb[flag+2])
	{
		if(numb[flag+1] < numb[flag+2])
		{
			power += numb[flag+1];
			flag = flag+1;
		}else
		{
			power += numb[flag+2];
			flag = flag+2;
		}
	}
	printf("\n最小能量值%d",power);
}