#include "stdio.h"
#include "stdlib.h"
main()
{
	int numb[100],answer=0,count;
	printf("��������������:");
	scanf("%d",&count);
	for(int i=0;i<count;i++){
		printf("��%d��ֵ:",i+1);
		scanf("%d",&numb[i]);
	}
	printf("���Ϊ: ");
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