#include <stdio.h>
#include "util.h"

int count;
int length;
char input[100];

int main()
{

	printf("Enter a line of characters>");
	fgets(input, 100, stdin);

    num_count(input);

	printf("%d\t%d\n", length, count);
	return 0;
}
