
#include "stdio.h"
#include "conio.h"
main()
{
  int x,y,z,t;
  scanf("%d%d%d",&x,&y,&z);
  if (x>y)
    {t=x;x=y;y=t;} /*����x,y��ֵ*/
  if(x>z)
    {t=z;z=x;x=t;} /*����x,z��ֵ*/
  if(y>z)
    {t=y;y=z;z=t;} /*����z,y��ֵ*/
  printf("small to big: %d %d %d\n",x,y,z);
  getch(); 
}