#include "stdio.h"
#include "stdlib.h"
int fun(int n);
main()
{
    int numb,t;
	printf("�����빲�ж��ٽ�̨��:");
	scanf("%d",&numb);
    t=fun(numb);
    printf("����%d���߷�\n",t);
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
