#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Node
{
	int id;
	int password;
	struct Node *next;
} List;

void new_list(List *L,int n);
void joseph(List *L,int m);
int del_m(List *s);

int main()
{
	int n=0;
	int m=0;
	List *L=(List *)malloc(sizeof(List));
	scanf("%d",&n);
	scanf("%d",&m);
	new_list(L,n);
	joseph(L,m);
	return 0;
}
void new_list(List *L,int n)
{
	int i;
	List *p,*q;
	L->next=L;
	p=L;
	p->id=1;
	scanf("%d",&(p->password));
	for(i=1;i<n;i++)
	{
		q=(List *)malloc(sizeof(List));
		q->id=i+1;
		scanf("%d",&(q->password));
		q->next=p->next;
		p->next=q;
		p=p->next;
	}
}
void joseph(List *L,int m)
{
	int i;
	List *p;
	p=L;
	while(p->next!=L)
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
	free(p);
}
int del_m(List *s)
{
	int m;
	List *p;
	p=s->next;
	s->next=p->next;
	m=p->password;
	free(p);
	return m;
}
