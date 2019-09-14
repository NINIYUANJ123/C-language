#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Node
{
	int id;
	int password;
	struct Node *next;
} List;

List L[MAX];

void new_list(int n);
void joseph(int m);
int del_m(List *s);

int main()
{
	int n=0;
	int m=0;
	scanf("%d",&n);
	scanf("%d",&m);
	new_list(n);
	joseph(m);
	return 0;
}
void new_list(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		L[i].id=i;
		scanf("%d",&(L[i].password));
		L[i].next=&(L[i+1]);
	}
	L[i-1].next=&(L[1]);
}
void joseph(int m)
{
	int i;
	List *p;
	p=&(L[1]);
	while(p->next!=&(L[1]))
	{
		p=p->next;
	}	
	while(p!=p->next)
	{
		for(i=1;i<m;i++)
		{
			p=p->next;
		}
		printf("%d ",p->next->id);
		m=del_m(p);
	}
	printf("%d",p->id);
}
int del_m(List *s)
{
	int m;
	m=s->next->password;
	s->next=s->next->next;
	return m;
}
