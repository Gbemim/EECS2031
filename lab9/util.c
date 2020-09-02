#include <stdio.h>
#include <stdlib.h>

/* Definition of structure extendableArray */

struct extendableArray {
   int *arr;	/* array of integers */
   int size;	/* number of elements currently stored in the array */
   int capacity;/* capacity of the currently allocated array */
};



/* Initializes the extendable array */

struct extendableArray *initArr()
{
   struct extendableArray *a = ( struct extendableArray * ) malloc( sizeof( struct extendableArray ) );
   if( !a ) {
	printf( "Insufficient memory!" );
	exit( 1 );
   }
   a->capacity = 4;		/* initial capacity */
   a->arr = ( int * ) malloc( a->capacity * sizeof( int ));
   if( !a->arr ) {
	printf( "Insufficient memory!" );
	exit(1) ;
   }
   a->size = 0;			/* no element added to the array yet */
   return a;
}


/* Initializes the extendable array given a capacity*/

struct extendableArray *initArrCapacity(int capacity)
{
   struct extendableArray *a = ( struct extendableArray * ) malloc(sizeof( struct extendableArray ) );
   if( !a ) {
	printf( "Insufficient memory!" );
	exit( 1 );
   }
   a->capacity = capacity;		/* initial capacity */
   a->arr = ( int * ) malloc( a->capacity * sizeof( int ));

   if( !a->arr ) {
	printf( "Insufficient memory!" );
	exit(1) ;
   }
   a->size = 0;			/* no element added to the array yet */
   return a;
}

/* Returns the size of the array */

int arrSize( struct extendableArray *a )
{
	return( a->size );
}



/* Returns the capacity of the array. */

int arrCapacity( struct extendableArray *a )
{
	return( a->capacity );
}



/* Returns true (1) if the array is empty, and false (0) otherwise. */

int isEmpty( struct extendableArray *a)
{
	return( a->size == 0 );
}



/* Returns true (1) if the array is full, and false (0) otherwise. */

int isFull( struct extendableArray *a )
{
	return( a->size ==  a->capacity );
}



/* Prints the error message msg. */

void printErr( char *msg )
{
   printf( "\n%s\n", msg );
}



/* Prints the content of the array. */

void printArray( struct extendableArray *a )
{
   int i;

   if( isEmpty( a ) )
	printErr( "printArray(): empty array." );

   for( i = 0; i < a->size; i++)
	printf( "%3d ",  a->arr[i] );

   printf("\n");
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/
/*************    DO NOT MODIFY FUNCTION HEADERS      *************/

/* Inserts integer d at the rear of the array, right behind the last element. */


void insertLast( struct extendableArray **a, int d )
{
   /* Add your implementation here */
    if (isFull(*a)){
        // make a new array with doubled capacity
        struct extendableArray *newArray = ( struct extendableArray * ) initArrCapacity(arrCapacity(*a) * 2);
        int i;

        // copy the old array contents to the new array
        for(i = 0; i < arrCapacity(*a); i++)
        {
            newArray->arr[i] = (*a)->arr[i];
        }

        // insert the new element
        newArray->arr[i] = d;

        // set the size of the new array
        newArray->size = (*a)->size + 1;

        // release the old array
        free((*a)->arr);
        free(*a);

        // assign the address of the new array
        *a = newArray;
    }
    else
    {
        (*a)->arr[(*a)->size] = d;
        (*a)->size++;
    }
}




/* Removes and returns the last element of the array (the element that was inserted last). */
/* If the array is empty, call printErr() to display a message and return -1. */

int removeLast( struct extendableArray **a )
{

	/* Add your implementation here */
	int result;
	if(isEmpty(*a))
    {
        printErr("printArray(): empty array.");
        result = -1;
    }
    else
    {
        // set the result from the back of the array
        result = (*a)->arr[(*a)->size-1];

        // decrease the size of the array
        (*a)->size--;

        // decrease the capacity of the array
        if(((*a)->size < arrCapacity(*a) / 4))
        {
            int newCap = arrCapacity(*a) / 2;
            if(newCap < 4)
                newCap = 4;

            // make an allocation for the new array
            struct extendableArray *newArray=( struct extendableArray * )initArrCapacity(newCap);

            int i;
            // copy the old array contents to the new array
            for(i = 0; i < (*a)->size; i++)
            {
                newArray->arr[i] = (*a)->arr[i];
            }

            // set the size of the new array
            newArray->size = (*a)->size;

            // release the old array from the memory
            free((*a)->arr);
            free(*a);

            // return the new array
            *a = newArray;
        }
    }

   return(result);  /* replace this line with your own code */
}


/************************** END OF FILE ***************************/

