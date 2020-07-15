#include <stdio.h>
#include "util.h"

/***************************************
* EECS2031 – Lab 7
* Filename: lab7a.c
* Author: Akerele, Gbemisola
* Email: gbemim@my.yorku.ca
* EECS login ID: 216167041
****************************************/

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
