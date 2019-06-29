#include "stdio.h"
#include "stdlib.h"
main()
{
	int i,j,d,k=0,count=0,numb[30],t;
	scanf("%d",&k);
	for(i = 0 ; i < k ; i ++)
		scanf("%d",&numb[i]);
	for(i = 0 ; i < k ; i ++)
	{
		for(j = i+1 ; j < k ; j ++)
		{
			if(numb[i] < numb[j])
			{
				d = numb[i];
				numb[i] = numb[j];
				numb[j] = d;
			}
		}
	}
	t = k-count;
	d = (numb[0]*numb[1]*numb[2]>numb[t-1]*numb[t-2]*numb[0]?numb[0]*numb[1]*numb[2]:numb[t-1]*numb[t-2]*numb[0]);
    printf("%d",d);
	system("pause");
	return 0;
}