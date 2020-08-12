#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file_read = fopen("./gbemi.txt", "r");
	FILE *file_write = fopen("./gbemis.txt", "w");

	if(file_read == NULL || file_write == NULL){
		printf("The file does not exit or wopuld not open or it is empty!\n");
		return -1;
	}

	char c;
	while ((c = fgetc(file_read)) != EOF)
	{
		if (c == '.')
		{
			c = '!';
		}
		fputc(c, file_write);
	}

	fclose(file_write);
	fclose(file_read);
	
}