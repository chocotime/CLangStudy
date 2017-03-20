#include <stdio.h>
int main(void) {
    int N;
    scanf("%d", &N);
    if(3<=N && N<=5000) {
        int rem = N%5;
        if(rem==0) {
          printf("%d\n", N/5);
          return 0;
        }
        while(rem%3!=0 && rem<=N) {
            rem+=5;
        }
        if(rem>N)
          printf("-1\n");
        else if(rem==N)
          printf("%d\n", rem/3);
        else
          printf("%d\n", (N-rem)/5+rem/3);
    }
    return 0;
}
