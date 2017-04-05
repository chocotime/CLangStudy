#include <stdio.h>

int main()
{
   int a,b,month;
   int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   int c=0;
   
   printf("몇월의 달력을 원하십니까? : ");
   scanf("%d",&month);
   
   printf("\n");
   
   printf("선택하신 %d 월의 달력입니다! \n",month);
   
   printf("\n");
   
   printf("일   월   화   수   목   금   토\n");
   
   int day[arr[month]+1];
   
   for(b=1;b<arr[month]+1;b++)
   {
      day[b]=b;
   }   
   
   for(b=month-1;b>0;b--)
      c=c+arr[b]%7;
   
      c=c%7;
      
   if(month==1 || month==10)
      c=0;
   
   for(b=-c+1;b<arr[month]+1;b++)
   {
      if(b<=0)
         printf("   ");
      else 
         printf("%d   ",day[b]);
      if(b%7==7-c)
      {
              if(month==1 || month==10)
                 break;
          printf("\n");
      }
      if(month==1 || month==10)
      {
         if(b%7==0)
            printf("\n");
      }
   }
      return 0;
   }
