#include <stdio.h>
#include <stdlib.h>

int main() {
     struct node
    {
        int data;
        struct node *next; //link
    }
    *p, *head, *last;

    head = malloc(sizeof(struct node));
    head->data = -22;
    head->next = NULL;
    last = head;
   

    p = malloc(sizeof(struct node));
    p->data = 4;
    p->next = NULL;
    last->next = p;
    last = p;

    while (p->next != NULL)
    {
        printf("This is the lined list: %i", p->data);
        p = p->next;
    }
     free(head);
     free(p);
   
    
    
}