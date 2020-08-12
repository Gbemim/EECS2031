#ifndef UTIL_H
#define UTIL_H
  extern struct extendableArray *initArr();
  extern int arrSize( struct extendableArray *a);
  extern int arrCapacity( struct extendableArray *a);
  extern int isEmpty( struct extendableArray *a);
  extern int isFull( struct extendableArray *a);
  extern void printErr( char *msg);
  extern void printArray( struct extendableArray *a);
  extern void insertLast( struct extendableArray **a, int d);
  extern int removeLast( struct extendableArray **a);
#endif

