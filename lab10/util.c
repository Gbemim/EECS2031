/***********************************
* EECS 2031 - Lab 10
* Filename: util.c
* Author: Akerele, Gbemisola
* Email: gbemim@my.yorku.ca
* Login ID: 216167041
************************************/

#include<stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1000

// Search input text file for str.
// Outputs each line which contains "str" into the "output" file

void search(FILE *input, FILE *output, char *str){
  /*************************
     implement some codes
  *************************/

    char buff[BUF_SIZE];

    while(fgets(buff, BUF_SIZE - 1, input))
    {
        int j = 0;
        int i = 0;

        while(buff[j] != '\0')
        {
            while(str[i] != '\0' && buff[j] != '\0' && buff[j] == str[i])
            {
                i++;
                j++;
            }

            if(str[i] == '\0')
            {
                fputs(buff, output);
                break;
            }

            i = 0;
            if(buff[j] != str[i])
            {
                j++;
            }
        }
    }






}
