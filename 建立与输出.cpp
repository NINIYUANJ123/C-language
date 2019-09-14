#include "stdio.h"
#include "stdlib.h"
struct Node
{
	int xi;
	int zhi;
	struct Node *next;
};
Node* Creat();
Node* sort(Node* A);
void add(Node* A,Node* B);
main()
{
	Node* A = Creat();
	Node* B = Creat();;
	A = sort(A);
	B = sort(B);
	add(A,B);
	return 0;
}
Node* Creat()
{
	int i=0;
	int q;
	Node* Head = (Node*)malloc(sizeof(Node));
	Node* New = Head;
	int xi,zhi,numb;
	scanf("%d",&numb);
	while((q=getchar())!='\n'&&q!=EOF);
	for(i=0;i<numb;i++)
	{
		scanf("(%d,%d)",&xi,&zhi);
		if(xi != 0)
		{
			Node* p = (Node*)malloc(sizeof(Node));
			p->xi = xi;
			p->zhi = zhi;
			New->next = p;
			New = p;
		}
	}
	New->next = NULL;
	return (Head);
}
Node* sort(Node* A)
{
	Node* p = A->next;
	Node* p1;
	int a;
	while(p!=NULL)
	{
		p1=p->next;
		while(p1!=NULL)
		{
			if(p1->zhi<p->zhi)
			{
				a = p1->zhi;
				p1->zhi = p->zhi;
				p->zhi = a;

				a=p1->xi;
				p1->xi = p->xi;
				p->xi = a;
			}
			p1 = p1->next;
		}
		p = p->next;
	}
	return A;
}

void add(Node* A,Node* B)
{
	Node* pa = A->next;
	Node* pb = B->next;
	Node* c  = (Node*)malloc(sizeof(Node));
	Node* pc ;
	pc = c
		;
	Node* t;
	while(pa!=NULL && pb!=NULL)
	{
		if(pa->zhi<pb->zhi)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		if(pa->zhi == pb->zhi)
		{
			int sum = pa->xi + pb->xi;
			if(sum != 0)
			{
				pa->xi = sum;
				pc->next = pa;
				pc = pa;
				pa = pa->next;
				t = pb;
				pb = pb->next;
				free(t);
			}
			else
			{
				t = pa;
				pa = pa->next;
				free(t);
				t = pb;
				pb = pb->next;
				free(t);
			}
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	if(pa!=NULL)
		pc->next = pa;
	else
		pc->next = pb;
	free(B);
	Node* p = c->next;
	while(p!=NULL)
	{
		if(p->zhi == 1)
			printf("%dX",p->xi);
		if(p->zhi > 1)
			printf("%dX^%d",p->xi,p->zhi);
		if(p->zhi == 0)
			printf("%d",p->xi);
		if(p->next!=NULL)
		{
			if(p->next->xi > 0)
				printf("+");
		}
		p = p->next;
	}	
}
