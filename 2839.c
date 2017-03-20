#include <stdio.h>
int main(void) {
    int N;
    scanf("%d", &N);
    if(3<=N && N<=5000) {
        int rem = N%5;
        
        while(rem%3!=0 && rem<=N) {
            rem+=5;
        }
        
        if(rem>N) 
          printf("-1\n");
        else if(rem==N) {
          if(rem%3!=0) 
              printf("-1\n");
          else 
              printf("%d\n", rem/3);
        }
        else
          printf("%d\n", (N-rem)/5+rem/3);
    }
    return 0;
}
