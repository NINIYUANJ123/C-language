#include "stdio.h"
#include "stdlib.h"
void choushu(int numb,int flag);
main()
{
	int numb;
	scanf("%d",&numb);
	choushu(numb,0);
}
void choushu(int numb,int flag)
{
	if(numb == 1 && flag == 1)
		printf("true");	
	else if(numb % 2 == 0)
		choushu(numb/=2,flag = 1);
	else if(numb%3 == 0)
		choushu(numb/= 3,flag = 1);
	else if(numb%5 == 0)
		choushu(numb/=5,flag = 1);
	else
		printf("no");
}
