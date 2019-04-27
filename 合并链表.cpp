#include <stdio.h>
#include <stdlib.h>
struct Data
{
	int number;
	struct Data *next;
};

void Create(struct Data *pHead)
{
	struct Data *p1, *t;
	int d;
	
	pHead->next = NULL;
	p1 = pHead;

	printf("ÇëÊäÈëÁ´±í:");
    scanf("%d", &d);
	while(d != 0) {
		t = (struct Data *)malloc(sizeof(struct Data));
		t->number = d;
		t->next = p1->next;
		p1->next = t;
		p1 = t;
		scanf("%d", &d);
	}
}

void print(struct Data *head) {
	struct Data *p = head->next;
	while(p != NULL) {
		printf("%d ", p->number);
		p = p->next;
	}
	printf("\n");
} 

struct Data *merge(struct Data *pHeadA, struct Data *pHeadB) {
	struct Data *pHead;
	struct Data *p1, *p2, *t;
	pHead = (struct Data *)malloc(sizeof(struct Data));
	pHead->next = NULL; 
	p1 = pHeadA->next; 
	p2 = pHeadB->next;
	t = pHead;
	while(p1 && p2) {
		if (p1->number <= p2->number) {
			t->next = p1;
			t = p1;
			p1 = p1->next;
		} else {
			t->next = p2;
			t = p2;
			p2 = p2->next;
		}
	}
	if (p1) {
		t->next = p1;
	} else {
		t->next = p2;
	}
	return pHead;
}

int main() {
	struct Data *pHead, *pHeadA, *pHeadB;
	pHead = (struct Data *)malloc(sizeof(struct Data));
	pHeadA = (struct Data *)malloc(sizeof(struct Data));
	pHeadB = (struct Data *)malloc(sizeof(struct Data));
	Create(pHeadA);
	print(pHeadA);
	Create(pHeadB);
	print(pHeadB);
	pHead = merge(pHeadA, pHeadB);
	print(pHead);
}
