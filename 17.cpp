#include "stdio.h"
#include "conio.h"
main()
{
  int score;
  char grade;
  printf("�������:\n");
  scanf("%d",&score);
  grade=score>=90?'A':(score>=60?'B':'C');
  printf("�ȼ�%c",grade);
  getch();
}