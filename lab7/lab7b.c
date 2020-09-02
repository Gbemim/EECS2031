#include <stdio.h>
#include "util.h"

int main()
{

    printf("Enter a line of characters>");
	fgets(input, 100, stdin);

    int_count(input);

}












































//int count, i;
//char input[100];
//
//while((input[i] != '\0'))
//{
//    if (input[i] >= '0' && input[i] <= 9)
//    {
//        if(b == 0)
//        {
//            b = 1;
//            count++;
//        }
//    }
//    else b = 0;
//    i++;
//}
//
//printf("%s\t, count");

















//    for(int i = 0; input[i] != '\0'; i++)
//    {
//        int numInput = input[i] - '0';
//        if((input[i+1] != ' ') || !((input[i+1] >= 'A') || (input[i+1] <= 'Z')) || input[i+1 != ','] || input[i+1] != '.'|| (input[i] != ' ') || !((input[i] >= 'A') || (input[i] <= 'Z')) || input[i != ','] || input[i] != '.')
//		{
//
//            while((input[i] >= '0') && (input[i] <= '9') && ((input[i + 1] >= '0') && (input[i + 1] <= '9')))
//            {
//                sum = (input[i] - '0') + (input[i+1] - '0');
//                length += 1;
//            }
//            count = sum;
//            printf("%d\t%d", length, count);
//
//        }
//	}





































//    for(int i = 0; input[i] != '\0'; i++)
//    {
//        if(((input[i] >= '0') && (input[i] <= '9')))
//        {
//            int j = 0;
//            char tmpInput[] = "";
//            while((input[j+1] >= '0') && (input[j] <= '9'))
//            {
//                tmpInput[j] = input[j+i];
//            }
//
//            for(int k = 0; tmpInput[k] != '\0'; k++)
//            {
//                sum += tmpInput[k] * pow(10, strlen(tmpInput) - k);
//            }
//
//            i = i + j;
//        }
//
//        printf("%d\n", sum);
//        return(0);
//    }
//
//
//
//
//
//
//
//
//










