#include<stdio.h>

int main (void){

        char arr[3][6]={{"APPLE\n"},{"GRAPE\n"},{"MANGO\0"}};
        char *p;
        char **pp;
        int i;


        p=arr;
        pp=&p;


        for(i=0;i<18;i++){
         printf("%c",*p);
         p++;
        }
        p=p-12;
        printf("\n%c\n",*p);
        printf("%c\n",*((*pp)+2));
        printf("%c\n",**pp);
         printf("%s\n",*(pp));

         *pp=(*pp)+3;

         printf("%c%c%c%c",*(*pp++),*(*pp+4),*(*pp-5),**pp);
        return 0;
}
