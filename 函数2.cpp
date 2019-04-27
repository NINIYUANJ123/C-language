#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 5
char name[N][10];
void compare()
{
	int k,flag = 0;
	for(int i = 0;i < 10;i++)
	{
		k = 0;
		for(int j = 1;j < N;j++)
		{
			if(name[0][i]==name[j][i] && k==3)
			{
				printf("%c",name[0][i]);
				break;
			}
			else if(name[0][i]==name[j][i])
				k++;
			else
			{
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			break;
	}

}
int main()
{
	printf("请输入五个字符串:\n");
	for(int i = 0;i < N;i++)
		scanf("%s",name[i]);
	printf("\n\n结果如下:\n");
	compare();
	system("pause");
	return 0;
}

