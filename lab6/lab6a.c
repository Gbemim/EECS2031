#include <stdio.h>

// ECS2031 – Lab 6
// Filename: lab6b.c
// Author: Akerele, Gbemisola
// Email: gbemim@my.yorku.ca
// EECS login ID: 216167041


float main()
{
	float input;
	//scanf("%f", &input);
	
	printf("Enter the measurement in inches>");
	scanf("%f", &input);
	while(input != 0) {
		printf("%.2f cm\n", input * 2.54);
		printf("Enter the measurement in inches>");
	        scanf("%f", &input);
	}  
	return 0;
}		
