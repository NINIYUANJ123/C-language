#include "stdio.h"
#include "stdlib.h"
char numb[10];
void print()
{
	int i,x1,x2=0,y1=1,y2,flag;
	x1=x2;
	for(i=0;i<5;i++)
	{
		if(numb[x2] != numb[x2+1])
		{	
			flag=0;
			if(x2>1)
			{
				for(i=x1;i<y1;i++)
				{
					if(numb[i] == numb[x2+1])
					{
						flag = 1;
						break;
					}
				}
			}
			x2++;
			if(flag == 0)
				y1++;
			else
			{
				y2=y1;
				y1=0;
				y1++;
			}
		}
	}
	if(y1<y2)
		printf("最长子串数为:%d",y2);
	else
		printf("最长子串数为:%d",y1);
}
int main()
{
	for(int i = 0;i < 6;i++)
		scanf("%c",&numb[i]);
	print();
	system("pause");
	return 0;
}