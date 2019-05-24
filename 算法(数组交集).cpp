#include<stdio.h>
#include<stdlib.h>
int Find(int a[],int b[],int c[],int sizea,int sizeb)
{
	int pa = 0;
	int pb = 0;
	int count = 0;
	while(pa < sizea && pb < sizeb)
	{
		if(a[pa] == a[pa+1])
			a[pa+1] = 0;
		else if(a[pb] == a[pb+1])
			b[pb+1] = 0;
		else if (a[pa] > b[pb])
			pb++;
		else if(a[pa] < b[pb])
			pa++;
		else
		{  c[count++] = a[pa];
		   pa++;
		   pb++;
		}
	}
	return (count);
}
void Sort(int s[],int v)
{
	int t,i,j;
	for(i = 0;i < v;i++)
	{
		for(j = i+1;j < v;j++)
		{
			if(s[i] > s[j])
			{
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
		}
	}
}
int main(void)
{
	int a[] = {4,9,5};
	int b[] = {9,4,9,8,4};
	int i,count,c[10]; 
	Sort(a,3);
	Sort(b,5);
	count = Find( a,b,c ,3,5);
	printf("相同的元素的为:\n");
	for(i = 0;i < count;i++)
	printf("%4d\n",c[i]);
	system("pause");
	return 0; 
} 
