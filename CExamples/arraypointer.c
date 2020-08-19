#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void main(){
  char t[][6]={"one","two","three"};
  printf("t[0]=%s, t[1]=%s, t[2]=%s\n", t[0], t[1], t[2]);
  printf("t[0]=%d, t[1]=%d, t[2]=%d\n", strlen(t[0]), strlen(t[1]), strlen(t[2]));
  printf("t[0]=%p, t[1]=%p, t[2]=%p\n", t[0], t[1], t[2]);

  char *s[]={"one", "two", "three"};
  
  printf("s[0]=%s, s[1]=%s, s[2]=%s\n", s[0], s[1], s[2]);
  printf("s[0]=%d, s[1]=%d, s[2]=%d\n", strlen(s[0]), strlen(s[1]), strlen(s[2]));
  printf("s[0]=%p, s[1]=%p, s[2]=%p\n", s[0], s[1], s[2]);

}
