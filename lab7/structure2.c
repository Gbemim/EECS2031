#include <stdio.h>

typedef struct {
    float width;
    float height;
    char *name;
} Dimensions;

Dimensions make_dimension(float width, float height, char *name){
   Dimensions result;
   result.width=width;
   result.height=height;
   result.name=name;
   
   printf("result address:%p\n", result);

   return result;
}

void main(){

	typedef struct {
		int x;
		int y;
	} Point;

	Point pt1, pt2;
	pt1.x=1;
	pt1.y=2;

	pt1 = pt1;

	printf("pt1 address=%p\n", pt1);
	printf("pt2 address=%p\n", pt2);
	printf("pt2.x=%d,pt2.y=%d\n", pt2.x, pt2.y);
        pt2.x=-1;
	pt2.y=-2;

	printf("pt2.x=%d,pt2.y=%d\n", pt2.x, pt2.y);
	printf("pt1.x=%d,pt1.y=%d\n", pt1.x, pt1.y);
       

        Dimensions sofa = make_dimension(2.0, 3.0, "Test");
	Dimensions coach = {1.0, 2.0, "Coach"};

        printf("sofa address=%p\n", sofa);

	//Dimentions armchair = sofa; // this does not work
	
	Dimensions armchair = sofa;

        armchair = coach;
        printf("armchair address:%p\n", armchair);	
        armchair = coach;
        printf("armchair address:%p\n", armchair);	

        printf("The sofa dimensions are width=%.2f, height=%.2f, name=%s\n", sofa.width, sofa.height, sofa.name);

        //printf("The armchair dimensions are width=%.2f, height=%.2f, name=%s\n", armchair->width, armchair->height, armchair->name);
        printf("The armchair dimensions are width=%.2f, height=%.2f, name=%s\n", armchair.width, armchair.height, armchair.name);


}

