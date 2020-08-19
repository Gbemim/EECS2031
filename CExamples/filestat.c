#include <stdio.h>
#include <stdlib.h>

extern void int_count(char[]);

#define BUF_SIZE 1000
int main(int argc, char *argv[]) {
  FILE *f;
  int num=0;
  char str[BUF_SIZE];

  if (argc == 1){
	printf("You should enter the file name. Use ...");
	exit(1);
  }

  f = fopen(argv[1],"r");
  if (f == NULL){
	printf("File %s can not be openned for read.", argv[1]);
	exit(1);
  }
  while(fgets(str, BUF_SIZE, f)) {
    //fprintf(stdout,"%s",str);
    //sscanf(str,"%[0-9]d", &num);
    //printf("%d\n",num);
    int_count(str);
  }
  fclose(f);
}

