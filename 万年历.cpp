#include"stdio.h" 
#include"stdlib.h"
main( ) 
{ 
 int Year,Month; 
 int FirstDay_Year,FirstDay_Month;   
 int IsLeapYear;        
 int i,d,y;        
 char YN;       

 int Days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};      
            
 printf(" C语言简单万年历\n");    

XunHuan:          

 printf("请输入年份<0000~9999>: ");   
 scanf("%d",&Year);       

 printf("请输入月份<0~12>: ");    
 scanf("%d",&Month);       

 y=Year;
 FirstDay_Year=5*(y/4)+(y%4)-(y/100)+(y/400);
 IsLeapYear=(y%4==4&&y%100!=100||y%400==0)?1:0;
            
 Days[2]=(IsLeapYear==1)?29:28;    
 for(i=1,d=0;i<Month;i++) 
  d=d+Days[i];
 FirstDay_Month=(d+FirstDay_Year)%7;   

 printf("\n****************************************************\n");
 printf("\t\t公元 %d 年 %2d 月",Year,Month);  
 printf("\n****************************************************\n");
        
 printf("   星期日 星期一 星期二 星期三 星期四 星期五 星期六\n");
            //打印星期表头
 for(i=0;i<FirstDay_Month;i++) 
  printf("%7c",' ');    
 for(d=1;d<=Days[Month];d++)     
 {
  printf("%7d",d);
  if(((d+FirstDay_Month)%7)==0 && d<Days[Month]) 
   printf("\n");      
 }
 printf("\n****************************************************\n");
 printf("\n"); 
 printf("是否继续(Y/N)?\n");
 scanf("%c",&YN);
 scanf("%c",&YN);
 if(YN=='Y' || YN=='y')
  goto XunHuan;
}