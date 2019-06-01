#include "stdio.h"
#include "stdlib.h"
struct numb
{
	int count;
	struct numb *next;
};
void yuesefu(struct numb *head,int n)
{
	struct numb *p1,*ghead,*r,*pp;
	p1 = head;
	head->count = 1;
	head->next = NULL;
	ghead = head;
	int i;
	for(i = 2;i <= n;i++)
	{
		struct numb *p;
		p = (struct numb*)malloc(sizeof(struct numb));
		p->count = i;
		p->next = NULL;
		p1->next = p;
		p1 = p1->next;
	}
	p1->next = head;
	int j=1;
	while(1)
	{
		if(j == 3)
		{
			if(ghead->next == r)
			{
				free(ghead);
				printf("%d",r->count);
				break;
			}
			pp = ghead->next;
			r->next = ghead->next;
			j=1;
			free(ghead);
			ghead = pp;
		}
		r = ghead;
		ghead = ghead->next;
		j++;
	}


}
main()
{
	int numb;
	struct numb *head;
	head = (struct numb*)malloc(sizeof(struct numb));
	yuesefu(head,5);
	system("pause");
	return 0;
}