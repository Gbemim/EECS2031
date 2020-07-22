#include <stdio.h>
#include "util.h"

/***************************************
* EECS2031 – Lab 8
* Filename: lab8b.c
* Author: Akerele, Gbemisola
* Email: gbemim@my.yorku.ca
* EECS login ID: 216167041
****************************************/


#define MAX_SIZE 100

int main() {
   char my_strg[ MAX_SIZE ];

   /* Call getaline and str_reverse here */
    getaline(my_strg, 100);
    str_reverse(my_strg);

    printf( "%s\n", my_strg );  /* output the reversed string */
}
