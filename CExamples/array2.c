#include <stdio.h>

void main(){
	int num[2][3] = {{1, 2, 3}, {4, 5, 6}};
	printf("%p\n", num[0][0]);
	printf("%p\n", num[0][1]);
}
