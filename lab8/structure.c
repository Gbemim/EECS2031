#include <stdio.h>

void main(){
	typedef struct {
	   float width;
	   float height;
	   char name[10];
	} Dimensions;
	
	Dimensions sofa = {2.0, 3.0, "Test"};

	printf("The sofa dimensions are width=%.2f, height=%.2f, name=%s\n", sofa.width, sofa.height, sofa.name);
	
}
