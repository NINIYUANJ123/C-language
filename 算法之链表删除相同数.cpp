#include "stdio.h"
#include "stdlib.h"
struct Data
{
	int numb;
	struct Data *next;
};
void Creat(struct Data *Head)
{
	struct Data *p,*pMove;
	int d;
	Head->next = NULL;
	p = Head;
	printf("请输入链表的数字(0结束):");
	scanf("%d",&d);
	while(d)
	{
		pMove = (struct Data *)malloc(sizeof(struct Data));
		pMove->numb = d;
		pMove->next = p->next;
		p->next = pMove;
		p = pMove;
		scanf("%d",&d);
	}
}

void Print(struct Data *Head)
{
	struct Data *p = Head->next;
	while(p!=NULL)
	{
		printf(" %d",p->numb);
		p = p->next;
	}
}
struct Data* Remove(struct Data *Head) {
    if (Head == NULL)
        return NULL;
    struct Data *p=Head->next;
    struct Data *s=p->next;
    while(p->next != NULL)
    {
        if (p->numb == s->numb)
        {
            if (s->next != NULL)
                {
                    p->next = s->next;
					free(s);
                    s=s->next;
                }
                else
                {
                    p->next =NULL;
                    break;
                }
        }
        else
        {
            s=s->next;
            p=p->next;
        }
    }
     return Head;
}

main()
{
	struct Data *Head = (struct Data *)malloc(sizeof(struct Data));
	Creat(Head);
	printf("\n原链表为:");
	Print(Head);
    Remove(Head);
	printf("\n新链表为:");
	Print(Head);
	system("pause");
}
