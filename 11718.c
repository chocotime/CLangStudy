#include <stdio.h>
int main(void) {
	int putting;
	int mkline = 0;
	while ( (putting=getchar()) != EOF ) {
		if(putting=='\n') mkline++;
		else mkline=0;
		if(mkline >= 2) break;
		putchar(putting);
	}
	return 0;
}
