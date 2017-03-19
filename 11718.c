#include <stdio.h>
int main(void) {
	int putting;
	int linecheck = 0, mkline=0;
	int n=0;
	while ( (putting=getchar()) != EOF ) {
		n++;
		printf("%d", n);
		if(putting=='\n') {
			mkline++;
			linecheck++;
			n=0;
		}
		else mkline=0;
		if(linecheck>100) {
			break;
		}
		if(mkline >= 2) break;
		if(n>100) break;
		putchar(putting);
	}
	return 0;
}
