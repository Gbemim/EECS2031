#include "util.h"
#include <stdio.h>

int count;
int length;
char input[100];


void num_count(char sentence[])
{

    for(int i = 0; input[i] != '\0'; i++)
    {
		if((input[i] >= '0') && (input[i] <= '9'))
		{
			count += input[i] - '0';
			length += 1;
		}
	}

}


void int_count(char input[])
{
    int sum = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        int numInput = input[i] - '0';
        if((input[i+1] != ' ') || !((input[i+1] >= 'A') || (input[i+1] <= 'Z')) || input[i+1 != ','] || input[i+1] != '.'|| (input[i] != ' ') || !((input[i] >= 'A') || (input[i] <= 'Z')) || input[i != ','] || input[i] != '.')
		{

            while((input[i] >= '0') && (input[i] <= '9') && ((input[i + 1] >= '0') && (input[i + 1] <= '9')))
            {
                sum = (input[i] - '0') + (input[i+1] - '0');
                length += 1;
            }
            count = sum;
            printf("%d\t%d", length, count);

        }
	}


}







































//    char inputChar = input[0];
//    int num = 0;
//    int sum = 0;
//    int flag = 0;
//    int i = 1;
//    int count = 0;
//
//    while(inputChar != '\0')
//    {
//        if(inputChar < '0' || inputChar > '9')
//        {
//            if(flag != 0)
//            {
//                sum += num;
//                count += 1;
//            }
//
//            num = 0;
//            flag = 0;
//            inputChar = input[i++];
//            continue;
//        }
//        num = (num * 10) + (inputChar - '0');
//        inputChar = input[i++];
//        flag = 1;
//    }

//   printf("%d\t%d\n", count, sum);


