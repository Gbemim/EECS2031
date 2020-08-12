/***********************************
* EECS 2031 - Lab 10
* Filename: lab10.c
* Author: Akerele, Gbemisola
* Email: gbemim@my.yorku.ca
* Login ID: 216167041
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main(int argc, char *argv[]) {
  FILE *input, *output;
  int num=0;

  // There should be 3 arguments passed to the main function
  if (argc < 4){
	printf("You should enter the input and output files and a search phrase.Example:\n");
	printf("lab10 myfile.txt out.txt nick\n");
	printf("lab10 myfile.txt stdout nick\n");
	exit(1);
  }

  // Check the input file

 /*************************
     implement some codes
  *************************/
    input = fopen(argv[1], "r");
    if(input == NULL)
    {
        printf("File \"%s\" can not be opened for reading.\n", argv[1]);
        exit(1);
    }

  // check for the output file. If the output file is stdout,
  // standard output would be the output file

 /*************************
     implement some codes
  *************************/
    if(!strcmp(argv[2], "stdout"))
    {
        output = stdout;
    } else output = fopen(argv[2], "w");

    if(input == NULL)
    {
        printf("File %s can not be opened for writing.\n", argv[2]);
        exit(1);
    }


  // call search function from util.c
 /*************************
     implement some codes
  *************************/
  search(input, output, argv[3]);

  // close all files before exit

 /*************************
     implement some codes
  *************************/
	fclose(input);
	if(strcmp(argv[2], "stdout")) fclose(output);
}
