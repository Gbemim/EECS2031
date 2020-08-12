#include <stdio.h>
#include <stdlib.h>

//Insert node at the begining 
struct node
{
    int data;
    struct node *next; //link
}
*temp, *head, *last;
int n, j;

void Insert(int num)
{
    temp = malloc(sizeof(struct node));
    temp->data = num;
    // temp->next = NULL;
    // if (head != NULL)
    // {
    //     temp->next = head;
    // } OR
    temp->next = head;
    head = temp;   
}

void Print()
{
    temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}

int main() {
   head = NULL; //EMPTY LIST
   printf("How many numbers do you you want to input?\n");
   scanf("%d", &n);
   for (int i = 0; i < n; i++)
   {
       printf("Please enter the number to insert to the list: \n");
       scanf("%d", &j);
       Insert(j);
       Print();

   }
   
    
}