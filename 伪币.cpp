\\��α�Ҵ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int numb[100];
int weight(int Start,int End)
{
	int weight = 0, i;
	for(i = Start;i <= End;i++)
		weight += numb[i];
	return weight;
}
int compare(int ls, int le, int rs, int re)
{
	int count ;
	printf("\n���� = %d \t ���� = %d \t ��ʼ = %d \t ���� = %d \n",ls+1, le+1, rs+1, re+1);
	printf("\n������ = %d \t ������ = %d\n",weight(ls, le), weight(rs,re));
	if (ls == le && rs == re) {
        if (weight(ls, le) < weight(rs, re)) {
            count = ls;
        } else {
            count = rs;
        }
    	printf("\nα����%d����",count+1);
    } else if (ls == le) {
        if (weight(ls, le) == 0) {
            count = ls;
            printf("\nα����%d����",count+1);
        } else {
            compare(rs, (rs + re) / 2, (rs + re) / 2 + 1, re);
        }
    } else if (rs == re) {
        if (weight(rs, re) == 0) {
            count = rs;
            printf("\nα����%d����",count+1);
        } else { 
            compare(ls, (ls + le) / 2, (ls + le) / 2 + 1, le);
        }
    } else {
        if (weight(ls, le) < weight(rs, re)) {
            compare(ls, (ls + le) / 2, (ls + le) / 2 + 1, le);
        } else if (weight(ls, le) > weight(rs, re)) {
            compare(rs, (rs + re) / 2, (rs + re) / 2 + 1, re);
        } else {
            if ((le - ls) > (re - rs)) {
                compare(ls, (ls + le) / 2, (ls + le) / 2 + 1, le);
            } else {
                compare(rs, (rs + re) / 2, (rs + re) / 2 + 1, re);
            }
        }
    }
	return 0;
}
int main()
{
	int n , i , count;
	printf("������Ӳ��������");
	scanf("%d", &n);
	srand(( unsigned ) time ( NULL ));
	count = rand() % n;
	for(i = 0;i < n; i++)
		numb[i] = 1; 
	numb[count-1] = 0;
	for( i = 0;i < n;i++)
		printf("%d",numb[i]);
	printf("\n%d",count);
	compare(0, n / 2 - 1, n / 2, n - 1);
	system("pause");
	return 0;
} 
