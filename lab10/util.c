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

    // Read each line of the input file and store into "buffer"
    while(fgets(buff, BUF_SIZE - 1, input))
    {
        int j = 0;

        // the outer loop is controlling read line from input
        int i = 0;

        while(buff[j] != '\0')
        {
            // the inner loop comparing characters of the "buffer" (curent line)
	        // with "str" (the input pattern)
            while(str[i] != '\0' && buff[j] != '\0' && buff[j] == str[i])
            {
                i++;
                j++;
            }

            // if "i" reaches '\0' it means the pattern is found and outputs the
	        // line into the "output" file
            if(str[i] == '\0')
            {
                fputs(buff, output);
                break;
            }

           	// note that we need to increment the line index until the end of the line
	        // if we we could not found the search pattern so far.
            i = 0;
            if(buff[j] != str[i])
            {
                j++;
            }
        }
    }






}
