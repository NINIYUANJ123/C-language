// 汽车.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>


struct SStud
{
	int nPrice;/*汽车的价格*/
	char sBrand[40];/*汽车品牌(型号)*/
	float fSpeed;/*汽车零百加速时间*/
};
typedef struct SStud DATA;
struct SNode
{
	DATA data;/*数据区*/
	struct SNode* pNext;/*地址区*/
}*g_pHead = NULL;;



void AddHead(DATA d)/*开头插入函数,添加函数的二级函数*/
{
	struct SNode* pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew->data = d;/*pNew ->data为一个数据区*/
	pNew->pNext = g_pHead;/*pNew ->pNext为一个地址,g_pHead为一个节点*/
	g_pHead = pNew;/*此方法为头插法*/
}


void AddTail(DATA d)/*尾部插入函数,添加函数的二级函数*/
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


void Print()/*就是个打印函数,几乎每个函数都要用到此函数,也可以说此函数是浏览排序函数的二级函数*/
{
	puts("\t\t\t\t品牌(型号)    价格(万)  零百加速(秒)\n");
	struct SNode* p = g_pHead;/*struct SNode* p为一个指针,先定义指针,后面才能用 p->什么什么*/
	while (p)/*循环链表*/
	{
		printf("\t\t\t\t%-30s\t%d\t%0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
		p = p->pNext;
	}

}


void Input()/*case2的添加函数,添加函数的一级函数*/
{
	char c = 0;
	do
	{
		system("cls");
		DATA d;
		printf("\n\n\t\t\t\t请输入汽车品牌(型号),价格和零百加速(秒):");
		scanf_s("%s %d %f", &d.sBrand, &d.nPrice, &d.fSpeed);
		puts("\n\t\t\t\t1,开头插入");/*两种数据插入方式供选择*/
		puts("\t\t\t\t2,结尾插入");
		int i = 0;
		printf("\t\t\t\t请选择插入方式:");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:
			AddHead(d);/*开头插入法*/
			break;
		case 2:
			AddTail(d);/*尾部插入法*/
			break;
		}
		Print();
		printf("\t\t\t\t是否继续添加? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');

}


int Remove(char sBrand[20])/*布尔型的删除函数的二级函数,形参为下面一级函数的品牌名称*/
{
	struct SNode* p = g_pHead, *p1;
	if (!strcmp(sBrand, p->data.sBrand))/*先进行品牌名称的比对,下面为删除头节点*/
	{
		g_pHead = p->pNext;/*头节点指向第二个节点,干掉老大*/
		free(p);
		return 1;
	}
	while (p)
	{
		if (!strcmp(p->data.sBrand, sBrand))/*比对品牌*/
		{
			p1->pNext = p->pNext;/*让p1指向的下一个变为p指向的下一个,就是跨国p*/
			free(p);/*释放掉p*/
			return 1;/*成功*/
		}
		p1 = p;/*p1为上一个节点的地址*/
		p = p->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	return 0;/*失败*/
}


void Delete()/*case3的删除函数的一级函数*/
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\t\t\t\t请输入要删除的汽车品牌(型号):");
		char sBrand[20];
		scanf_s("%s", &sBrand);
		if (Remove(sBrand))/*删除函数的二级函数返回1就成功删除,返回0就是else失败*/
			puts("\n\t\t\t\t删除成功");
		else
			puts("\n\t\t\t\t该型号不存在");
		Print();
		printf("\t\t\t\t是否继续删除? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');
}


void ModifyData(char sBrand[20])/*修改函数的二级函数,此形参为下面一级函数中输入的品牌名称*/
{
	struct SNode* p = g_pHead;
	while (p)/*循环链表*/
	{
		if (!strcmp(p->data.sBrand, sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("请重新输入新的价格与零百加速时间:");
			float fSpeed;
			int nPrice;
			scanf_s("%d %f", &nPrice, &fSpeed);
			p->data.fSpeed = fSpeed;/*将新的数据对要修改的数据进行覆盖*/
			p->data.nPrice = nPrice;
			Print();
			return;
		}
		p = p->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void Modify()/*case4的修改函数的一级函数*/
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\n\t\t\t\t请输入要修改的汽车品牌(型号):");
		char sBrand[20];
		scanf_s("%s", &sBrand);
		ModifyData(sBrand);/*将输入的品牌通过修改函数的二级函数处理*/
		printf("\t\t\t\t是否继续修改? [y/n]");
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
		struct SNode* p = g_pHead;/*struct SNode* p为一个指针,先定义指针*/
		int nPrice = 0;
		printf("\n\t\t\t\t请输入价格:");
		scanf_s("%d", &nPrice);
		puts("\t\t\t\t品牌(型号)\t价格(万)\t零百加速(秒)");
		while (p)
		{
			if (p->data.nPrice == nPrice)/*比对相同的价格*/
			{
				printf("\t\t\t\t%-14s\t%d\t%0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
				break;
			}
			p = p->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');
}


void FindbyBrand()/*通过字符品牌查找*/
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t请输入要查找找的品牌(型号):");
		scanf_s("%s", sBrand);
		while (p)/*循环链表*/
		{
			if (strcmp(p->data.sBrand, sBrand) == 0)/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
				printf("\t\t\t\t%-14s\t%d\t%0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
			p = p->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');

}


void FindbySpeed()/*通过加速时间段查找*/
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;
		float fMin;/*设定两个参数用来定义两个时间段*/
		float fMax;
		printf("\t\t\t\t请输入零百加速时间段的初末时间(使用空格间隔):");
		scanf_s("%f %f", &fMin, &fMax);
		while (p)/*循环链表*/
		{
			if ((p->data.fSpeed >= fMin) && (p->data.fSpeed <= fMax))/*比对加速时间是否在此时间段内*/
				printf("\t\t\t\t品牌(型号): %-14s\t价格(万): %d\t零百加速(秒): %0.1f\n", p->data.sBrand, p->data.nPrice, p->data.fSpeed);
			p = p->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'N' && c != 'n');

}


int Find()/*case5的查找函数,用int是为了查找查不到的时候可以回到主菜单*/
{
	system("cls");
	puts("\n\n\t\t\t\t* * * * * * * * * * * * * *");
	puts("\t\t\t\t*1,按品牌(型号)查找       *");
	puts("\t\t\t\t*2,按价格查找             *");
	puts("\t\t\t\t*3,按零百加速时间段段查找 *");
	puts("\t\t\t\t*0,返回主菜单             *");
	puts("\t\t\t\t* * * * * * * * * * * * * *");
	int i = 0;
	printf("\t\t\t\t请选择您所需的查找方式:");
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


void SortbyPrice()/*按照价格高低排序*/
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
		printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'Y' && c != 'y');

}


void SortbySpeed()/*按照零百加速速度时间长短排序*/
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
		printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'Y' && c != 'y');

}


void sortbyInput()/*按照原始输入数据时的顺序直接输出,其实就是前面的Print函数*/
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch_s();
		putch_s(c);
		putch_s('\n');
	} while (c != 'Y' && c != 'y');

}


int Browse()/*case1的浏览函数,共三种浏览排序模式*/
{
	system("cls");
	puts("\n\n\t\t\t\t* * * * * * * * * * * *");
	puts("\t\t\t\t*1,按原始数据排序     *");
	puts("\t\t\t\t*2,按价格排序         *");
	puts("\t\t\t\t*3,按零百加速时间排序 *");
	puts("\t\t\t\t*0,返回主菜单         *");
	puts("\t\t\t\t* * * * * * * * * * * *");
	int i = 0;
	printf("\n\t\t\t\t请选择您所需的排序方式:");
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


void Save()/*保存函数*/
{
	FILE* fp;
	fp = fopen_s("./stud.", "wb");/*stud为数据的文件名*/
	SNode* p = g_pHead;
	while (p)/*依次循环到链表结尾*/
	{
		fwrite(&p->data, 1, sizeof(p->data), fp);//第一个成员变量的地址和结构体的地址是相同的,所以p和*/
		p = p->pNext;
	}
	fclose(fp);
}


void Load()/*加载数据函数*/
{
	FILE* fp;
	DATA data;
	fp = fopen_s("./stud.", "rb");
	while (fread(&data, 1, sizeof(data), fp))
		AddTail(data);
	fclose(fp);

}


int Menu()/*主菜单函数,2级函数*/
{
	system("cls");
	puts("\n\n\t\t\t\t* * * * * * * * *");
	puts("\t\t\t\t*1, 浏览所有信息*");
	puts("\t\t\t\t*2, 添加信息    *");
	puts("\t\t\t\t*3, 删除信息    *");
	puts("\t\t\t\t*4, 修改信息    *");
	puts("\t\t\t\t*5, 查找信息    *");
	puts("\t\t\t\t*0, 退出        *");
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


int main(int argc, char* argv[])/*主函数,1级函数*/
{
	Load();
	system("color F2");
	int i = 3;
	char c = 0;
	do
	{
		system("cls");
		i = i - 1;
		puts("\n\n\t\t\t\t* * * * * * * * * * *");/*登录密码,然后匹配成功后进入菜单函数*/
		puts("\t\t\t\t*请输入四位登录密码:*");
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
			printf("\t\t\t\t(输入有误,请重新输入,您还有%d次机会)\n\n", i);
		printf("\t\t\t\t  退出请按[n]  继续请按[y]");
		c = getch_s();
		putch_s('\n');

	} while (i && c != 'N' && c != 'n');
	Save();
}