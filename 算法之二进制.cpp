#include "stdio.h"
#include "stdlib.h"
main()
{
	int numb[100],answer=0,count;
	printf("请输入数组数量:");
	scanf("%d",&count);
	for(int i=0;i<count;i++){
		printf("第%d个值:",i+1);
		scanf("%d",&numb[i]);
	}
	printf("结果为: ");
	for(i=0;i<count;i++)
	{
		answer=(answer*2 + numb[i])%5;
		if(answer==0)
			printf("True ");
		else
			printf("False ");
	}
	system("pause");
}