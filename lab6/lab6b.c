#include <stdio.h>
#include <string.h> 

// ECS2031 – Lab 6
// Filename: lab6b.c
// Author: Akerele, Gbemisola
// Email: gbemim@my.yorku.ca
// EECS login ID: 216167041


int main() {
	
	int count;
	char input[100];
	
	printf("Enter a line of characters>");
	fgets(input, 100, stdin);
	
	for(int i = 0; input[i] != '\0'; i++) {
		if(input[i] == ' ') {
			count++;
		}
	}
	printf("%i\n", count);
	return 0;
}
