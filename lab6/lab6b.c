#include <stdio.h>
#include <string.h> 

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
