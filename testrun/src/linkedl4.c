#include <stdio.h>
#include <stdlib.h>
// delete a node at nth position


struct node
{
    int data;
    struct node* next;
}
*head;

void Insert(int num) // insert an integer at the end of the list
{
    struct node *temp = (struct node*) malloc(sizeof(struct node*)); 
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

void Print() // print all the elements in the list
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void Delete(int position) // deletes node at position
{
    struct node *temp = head; 
    if (position == 1)
    {
        head = temp->next;
        free(temp);
        return;
    } else
    {
        int  i;
        for (i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }

        struct node *temp2 = head; 
        temp->next = temp2->next;
        temp2->next = temp;

        free(temp2);
    }
    
}

int main() 
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print(); // List: 2, 4, 6, 5

   int n;
   printf("Enter a position\n");
   scanf("%d", &n);
   Delete(n);
   Print();


    
}