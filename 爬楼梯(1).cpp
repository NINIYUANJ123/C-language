#include "stdio.h"
#include "stdlib.h"
int fun(int n);
main()
{
    int numb,t;
	printf("请输入共有多少节台阶:");
	scanf("%d",&numb);
    t=fun(numb);
    printf("共有%d种走法\n",t);
	system("pause");
    return 0;
}
int fun(int n)
{
    int s;
    if(n==1)
        s=1;
    else if(n==2)
        s=2;
    else
        s=fun(n-1)+fun(n-2);
    return s;
}
