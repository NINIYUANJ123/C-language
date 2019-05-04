#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"
int numb1[100][3];
void add();
void jisuan();
int d=0;
main()
{
	add();
	jisuan();
	getch();
	return 0;
}
void add()
{
	int i;
	printf("共几组坐标：");
	scanf("%d",&d);
	for(i = 0;i < d;i++)
	{
		printf("请输入第%d组坐标：",i+1);
		scanf("%d %d",&numb1[i][0],&numb1[i][1]);
	}
}
void jisuan()
{
	int i,j,s1,s2;
	float s;
	puts("\n\n计算结果为：");
	printf("        (%d,%d)      (%d,%d)      (%d,%d)",numb1[0][0],numb1[0][1],numb1[1][0],numb1[1][1],numb1[2][0],numb1[2][1]);
	for(i = 0;i < d;i++)
	{
		printf("      \n(%d,%d)",numb1[i][0],numb1[i][1]);
		for(j = 0;j < d;j++)
		{
			s1 = numb1[i][0] - numb1[j][0];
			s2 = numb1[i][1] - numb1[j][1];
			s = sqrt(s1 * s1 + s2 * s2);
			printf("   %f",s);
		}
	}
}
