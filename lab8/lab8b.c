#include <stdio.h>
#include "util.h"


#define MAX_SIZE 100

int main() {
   char my_strg[ MAX_SIZE ];

    /* call getaline and octal2decimal functions here */

    getaline(my_strg, 100);
    int my_int = octal2decimal(my_strg);

    printf( "%d\n", my_int);  /* output the decimal number */
}
