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
            
 printf(" C���Լ�������\n");    

XunHuan:          

 printf("���������<0000~9999>: ");   
 scanf("%d",&Year);       

 printf("�������·�<0~12>: ");    
 scanf("%d",&Month);       

 y=Year;
 FirstDay_Year=5*(y/4)+(y%4)-(y/100)+(y/400);
 IsLeapYear=(y%4==4&&y%100!=100||y%400==0)?1:0;
            
 Days[2]=(IsLeapYear==1)?29:28;    
 for(i=1,d=0;i<Month;i++) 
  d=d+Days[i];
 FirstDay_Month=(d+FirstDay_Year)%7;   

 printf("\n****************************************************\n");
 printf("\t\t��Ԫ %d �� %2d ��",Year,Month);  
 printf("\n****************************************************\n");
        
 printf("   ������ ����һ ���ڶ� ������ ������ ������ ������\n");
            //��ӡ���ڱ�ͷ
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
 printf("�Ƿ����(Y/N)?\n");
 scanf("%c",&YN);
 scanf("%c",&YN);
 if(YN=='Y' || YN=='y')
  goto XunHuan;
}