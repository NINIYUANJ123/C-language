#include "stdio.h"
#include "stdlib.h"
struct Data
{
	int numb;
	struct Data *next; 
};
int count=1;
void Creat(struct Data *pHead)
{
	struct Data *p1, *t;
	int d;
	pHead->next = NULL;
	p1 = pHead;
	printf("请输入链表:");
    scanf("%d", &d);
	while(d != 0) 
	{
		count++;
		t = (struct Data *)malloc(sizeof(struct Data));
		t->numb = d;
		t->next = p1->next;
		p1->next = t;
		p1 = t;
		scanf("%d", &d);
	}
}

void remove(struct Data *pHead)
{
	struct Data *p1,*p;
	p= pHead;
	int n,i=0;
	printf("请输入您要删除的节点位置:");
	scanf("%d",&n);
	while(p->next!=NULL)
	{
		i++;
		p1=p;
		p=p->next;
		if(i==(count-n))
		{
			p1->next = p->next;
			free(p);
			p=p1->next;
		}
		printf("%d",p->numb);
	}
}
main()
{
	struct Data *pHead = (struct Data *)malloc(sizeof(struct Data));
	Creat(pHead);
	remove(pHead);
	system("pause");
	return 0;
}