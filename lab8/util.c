#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/***************************************
* EECS2031 – Lab 8
* Filename: util.c
* Author: Akerele, Gbemisola
* Email: gbemim@my.yorku.ca
* EECS login ID: 216167041
****************************************/


// get a line of characters, skips the new line character
int getaline(char s[],int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
      s[i] = c;
  }
  s[i] = '\0';
  return i;
}

// copies the content of a string to another string
void mystrcpy(char *dest, char *src)
{
  while ((*dest++ = *src++) != '\0' ) ;
}

// finds the length of a string
int str_len(char *s)
{
  char *p = s;
  while (*p != '\0')
     p++;
  return p - s;
}

// reverses a given string
void str_reverse(char *str){
 /* Implement the body of the function */
    int length = str_len(str);
    char *start = str;
    char *end = str;
    char temp;

    for (int i = 1; i < length; i++)
    {
        end++;
    }

    for (int i = 0; i < length / 2; i++)
    {
        temp   = *end;
        *end   = *start;
        *start = temp;
        start++;
        end--;
    }

}


// converts an octal number to the decimal number
int octal2decimal(char *str){
  /* Implement the body of the function */
    int num = 0;
    int i = 0;
    int decNum = atoi(str);
    int last_num = decNum  % 10;

    if(!((*str - '0' >= 0 && *str - '0' <= 9) || (*str - '0' <= 0 && *str - '0' <= 9)))
    {
        printf("Error: not an octal number\n");
        exit (0);
    }
    else if(last_num == 9 || last_num == 8 )
    {
        printf("Error: not an octal number\n");
        exit(0);
    }
    else
    {
        while(decNum != 0)
        {
            num += (decNum % 10) * pow(8, i++);
            decNum /= 10;
        }
    }
    return num;
}

