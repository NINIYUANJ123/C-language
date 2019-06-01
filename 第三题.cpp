#include "stdio.h"
#include "conio.h"
int main()
{
	int i,j,n,sum,sum1;
	sum=0;
	printf("«Î ‰»În:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum1=0;
		for(j=1;j<=i;j++)
		{
			sum1+=j;
		}
		sum+=sum1;
	}
	printf("%d",sum);
	getch();
	return 0;
}