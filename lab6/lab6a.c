#include <stdio.h>

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
