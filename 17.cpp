#include "stdio.h"
#include "conio.h"
main()
{
  int score;
  char grade;
  printf("输入分手:\n");
  scanf("%d",&score);
  grade=score>=90?'A':(score>=60?'B':'C');
  printf("等级%c",grade);
  getch();
}