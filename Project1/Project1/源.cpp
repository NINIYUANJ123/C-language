// ����.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>


struct SStud
{
	int nPrice;/*�����ļ۸�*/
	char sBrand[40];/*����Ʒ��(�ͺ�)*/
	float fSpeed;/*������ټ���ʱ��*/
};
typedef struct SStud DATA;
struct SNode
{
	DATA data;/*������*/
	struct SNode* pNext;/*��ַ��*/
}*g_pHead = NULL;;



void AddHead(DATA d)/*��ͷ���뺯��,��Ӻ����Ķ�������*/
{
	struct SNode* pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew->data = d;/*pNew ->dataΪһ��������*/
	pNew->pNext = g_pHead;/*pNew ->pNextΪһ����ַ,g_pHeadΪһ���ڵ�*/
	g_pHead = pNew;/*�˷���Ϊͷ�巨*/
}


void AddTail(DATA d)/*β�����뺯��,��Ӻ����Ķ�������*/
{
	struct SNode* p = g_pHead;
	struct SNode *pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew->data = d;
	pNew->pNext = NULL;
	if (!p)
	{
		g_pHead = pNew;
		return;
	}
	while (p->pNext)
		p = p->pNext;
	p->pNext = pNew;

}


void Print()/*���Ǹ���ӡ����,����ÿ��������Ҫ�õ��˺���,Ҳ����˵�˺���������������Ķ�������*/
{
	puts("\t\t\t\tƷ��(�ͺ�)    �۸�(��)  ��ټ���(��)\n");
	struct SNode* p = g_pHead;/*struct SNode* pΪһ��ָ��,�ȶ���ָ��,��������� p->ʲôʲô*/
	while (p)/*ѭ������*/
	{
		printf("\t\t\t\t%-30s\t%d\t%0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
		p = p->pNext;
	}

}


void Input()/*case2����Ӻ���,��Ӻ�����һ������*/
{
	char c = 0;
	do
	{
		system("cls");
		DATA d;
		printf("\n\n\t\t\t\t����������Ʒ��(�ͺ�),�۸����ټ���(��):");
		scanf_s("%s %d %f", &d.sBrand, &d.nPrice, &d.fSpeed);
		puts("\n\t\t\t\t1,��ͷ����");/*�������ݲ��뷽ʽ��ѡ��*/
		puts("\t\t\t\t2,��β����");
		int i = 0;
		printf("\t\t\t\t��ѡ����뷽ʽ:");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:
			AddHead(d);/*��ͷ���뷨*/
			break;
		case 2:
			AddTail(d);/*β�����뷨*/
			break;
		}
		Print();
		printf("\t\t\t\t�Ƿ�������? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');

}


int Remove(char sBrand[20])/*�����͵�ɾ�������Ķ�������,�β�Ϊ����һ��������Ʒ������*/
{
	struct SNode* p = g_pHead, *p1;
	if (!strcmp(sBrand, p->data.sBrand))/*�Ƚ���Ʒ�����Ƶıȶ�,����Ϊɾ��ͷ�ڵ�*/
	{
		g_pHead = p->pNext;/*ͷ�ڵ�ָ��ڶ����ڵ�,�ɵ��ϴ�*/
		free(p);
		return 1;
	}
	while (p)
	{
		if (!strcmp(p->data.sBrand, sBrand))/*�ȶ�Ʒ��*/
		{
			p1->pNext = p->pNext;/*��p1ָ�����һ����Ϊpָ�����һ��,���ǿ��p*/
			free(p);/*�ͷŵ�p*/
			return 1;/*�ɹ�*/
		}
		p1 = p;/*p1Ϊ��һ���ڵ�ĵ�ַ*/
		p = p->pNext;/*ѭ�����������һ��.���±���*/
	}
	return 0;/*ʧ��*/
}


void Delete()/*case3��ɾ��������һ������*/
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\t\t\t\t������Ҫɾ��������Ʒ��(�ͺ�):");
		char sBrand[20];
		scanf_s("%s", &sBrand);
		if (Remove(sBrand))/*ɾ�������Ķ�����������1�ͳɹ�ɾ��,����0����elseʧ��*/
			puts("\n\t\t\t\tɾ���ɹ�");
		else
			puts("\n\t\t\t\t���ͺŲ�����");
		Print();
		printf("\t\t\t\t�Ƿ����ɾ��? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');
}


void ModifyData(char sBrand[20])/*�޸ĺ����Ķ�������,���β�Ϊ����һ�������������Ʒ������*/
{
	struct SNode* p = g_pHead;
	while (p)/*ѭ������*/
	{
		if (!strcmp(p->data.sBrand, sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("�����������µļ۸�����ټ���ʱ��:");
			float fSpeed;
			int nPrice;
			scanf_s("%d %f", &nPrice, &fSpeed);
			p->data.fSpeed = fSpeed;/*���µ����ݶ�Ҫ�޸ĵ����ݽ��и���*/
			p->data.nPrice = nPrice;
			Print();
			return;
		}
		p = p->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void Modify()/*case4���޸ĺ�����һ������*/
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\n\t\t\t\t������Ҫ�޸ĵ�����Ʒ��(�ͺ�):");
		char sBrand[20];
		scanf_s("%s", &sBrand);
		ModifyData(sBrand);/*�������Ʒ��ͨ���޸ĺ����Ķ�����������*/
		printf("\t\t\t\t�Ƿ�����޸�? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');
}


void FindbyPrice()
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;/*struct SNode* pΪһ��ָ��,�ȶ���ָ��*/
		int nPrice = 0;
		printf("\n\t\t\t\t������۸�:");
		scanf_s("%d", &nPrice);
		puts("\t\t\t\tƷ��(�ͺ�)\t�۸�(��)\t��ټ���(��)");
		while (p)
		{
			if (p->data.nPrice == nPrice)/*�ȶ���ͬ�ļ۸�*/
			{
				printf("\t\t\t\t%-14s\t%d\t%0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
				break;
			}
			p = p->pNext;
		}
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');
}


void FindbyBrand()/*ͨ���ַ�Ʒ�Ʋ���*/
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t������Ҫ�����ҵ�Ʒ��(�ͺ�):");
		scanf_s("%s", sBrand);
		while (p)/*ѭ������*/
		{
			if (strcmp(p->data.sBrand, sBrand) == 0)/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
				printf("\t\t\t\t%-14s\t%d\t%0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
			p = p->pNext;
		}
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');

}


void FindbySpeed()/*ͨ������ʱ��β���*/
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;
		float fMin;/*�趨��������������������ʱ���*/
		float fMax;
		printf("\t\t\t\t��������ټ���ʱ��εĳ�ĩʱ��(ʹ�ÿո���):");
		scanf_s("%f %f", &fMin, &fMax);
		while (p)/*ѭ������*/
		{
			if ((p->data.fSpeed >= fMin) && (p->data.fSpeed <= fMax))/*�ȶԼ���ʱ���Ƿ��ڴ�ʱ�����*/
				printf("\t\t\t\tƷ��(�ͺ�): %-14s\t�۸�(��): %d\t��ټ���(��): %0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
			p = p->pNext;
		}
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');

}


int Find()/*case5�Ĳ��Һ���,��int��Ϊ�˲��Ҳ鲻����ʱ����Իص����˵�*/
{
	system("cls");
	puts("\n\n\t\t\t\t* * * * * * * * * * * * * *");
	puts("\t\t\t\t*1,��Ʒ��(�ͺ�)����       *");
	puts("\t\t\t\t*2,���۸����             *");
	puts("\t\t\t\t*3,����ټ���ʱ��ζβ��� *");
	puts("\t\t\t\t*0,�������˵�             *");
	puts("\t\t\t\t* * * * * * * * * * * * * *");
	int i = 0;
	printf("\t\t\t\t��ѡ��������Ĳ��ҷ�ʽ:");
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		FindbyBrand();
		break;
	case 2:
		FindbyPrice();
		break;
	case 3:
		FindbySpeed();
		break;
	default:

		return i;
	}
	return i;
}


void SortbyPrice()/*���ռ۸�ߵ�����*/
{
	char c = 0;
	do {
		system("cls");
		struct SNode * p = g_pHead, *q, *pMin;
		while (p)
		{
			pMin = p;
			q = p->pNext;
			while (q)
			{
				if (q->data.nPrice < pMin->data.nPrice)
					pMin = q;
				q = q->pNext;
			}
			if (p != pMin)
			{
				DATA t = p->data;
				p->data = pMin->data;
				pMin->data = t;
			}
			p = p->pNext;
		}
		Print();
		printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'Y' && c != 'y');

}


void SortbySpeed()/*������ټ����ٶ�ʱ�䳤������*/
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode * p = g_pHead, *q, *pMin;
		while (p)
		{
			pMin = p;
			q = p->pNext;
			while (q)
			{
				if (q->data.fSpeed < pMin->data.fSpeed)
					pMin = q;
				q = q->pNext;
			}
			if (p != pMin)
			{
				DATA t = p->data;
				p->data = pMin->data;
				pMin->data = t;
			}
			p = p->pNext;
		}
		Print();
		printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'Y' && c != 'y');

}


void sortbyInput()/*����ԭʼ��������ʱ��˳��ֱ�����,��ʵ����ǰ���Print����*/
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'Y' && c != 'y');

}


int Browse()/*case1���������,�������������ģʽ*/
{
	system("cls");
	puts("\n\n\t\t\t\t* * * * * * * * * * * *");
	puts("\t\t\t\t*1,��ԭʼ��������     *");
	puts("\t\t\t\t*2,���۸�����         *");
	puts("\t\t\t\t*3,����ټ���ʱ������ *");
	puts("\t\t\t\t*0,�������˵�         *");
	puts("\t\t\t\t* * * * * * * * * * * *");
	int i = 0;
	printf("\n\t\t\t\t��ѡ�������������ʽ:");
	scanf_s("%d", &i);
	switch (i)
	{
	case 2:
		SortbyPrice();
		break;
	case 3:
		SortbySpeed();
		break;
	case 1:
		sortbyInput();
		break;
	default:
		return i;
	}
	return i;
}


void Save()/*���溯��*/
{
	FILE* fp;
	fp = fopen_s("./stud.", "wb");/*studΪ���ݵ��ļ���*/
	SNode* p = g_pHead;
	while (p)/*����ѭ���������β*/
	{
		fwrite(&p->data, 1, sizeof(p->data), fp);//��һ����Ա�����ĵ�ַ�ͽṹ��ĵ�ַ����ͬ��,����p��*/
		p = p->pNext;
	}
	fclose(fp);
}


void Load()/*�������ݺ���*/
{
	FILE* fp;
	DATA data;
	fp = fopen_s("./stud.", "rb");
	while (fread(&data, 1, sizeof(data), fp))
		AddTail(data);
	fclose(fp);

}


int Menu()/*���˵�����,2������*/
{
	system("cls");
	puts("\n\n\t\t\t\t* * * * * * * * *");
	puts("\t\t\t\t*1, ���������Ϣ*");
	puts("\t\t\t\t*2, �����Ϣ    *");
	puts("\t\t\t\t*3, ɾ����Ϣ    *");
	puts("\t\t\t\t*4, �޸���Ϣ    *");
	puts("\t\t\t\t*5, ������Ϣ    *");
	puts("\t\t\t\t*0, �˳�        *");
	puts("\t\t\t\t* * * * * * * * *");
	int i = 0;
	printf("\t\t\t\t      ");
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		while (Browse())
			;
		Print();
		break;
	case 2:
		Input();
		break;
	case 3:
		Delete();
		break;
	case 4:
		Modify();
		break;
	case 5:
		while (Find())
			;
		break;
	}
	return i;

}


int main(int argc, char* argv[])/*������,1������*/
{
	Load();
	system("color F2");
	int i = 3;
	char c = 0;
	do
	{
		system("cls");
		i = i - 1;
		puts("\n\n\t\t\t\t* * * * * * * * * * *");/*��¼����,Ȼ��ƥ��ɹ������˵�����*/
		puts("\t\t\t\t*��������λ��¼����:*");
		puts("\t\t\t\t* * * * * * * * * * *");
		char x[20] = { 0 };
		char y[] = { "aaaa" };
		printf("\t\t\t\t");
		scanf_s("%s", x);
		if (!strcmp(x, y))
		{
			while (Menu());
			char c = 'n';
			break;
		}
		else
			printf("\t\t\t\t(��������,����������,������%d�λ���)\n\n", i);
		printf("\t\t\t\t  �˳��밴[n]  �����밴[y]");
		c = getch_s();
		putch_s('\n');

	} while (i && c != 'N' && c != 'n');
	Save();
}