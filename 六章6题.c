#include <stdlib.h>
#include <stdio.h>
#include <time.h>
main()
{
	int i,a[10],k,n=0;
    srand( (unsigned)time( NULL ) );
	printf("请输入数值n:");
	scanf("%d",&n);
	printf("原始数据为:");
    for( i = 0; i < n;i++ )
	{
		a[i]=rand()%100;
        printf( " [%d] ",a[i]);
	}
	for(i=0;i<=n/2;i++)
	{
		k=a[n-1-i];
		a[n-1-i]=a[i];
		a[i]=k;
	}
	printf("\n\n交换顺序为:");
	for(i=0;i<n;i++)
		printf(" [%d] ",a[i]);
	system("pause");
	return 0;
}