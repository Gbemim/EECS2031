#include <stdio.h>
#include <stdlib.h>
// Insert a node at nth position


struct node
{
    int data;
    struct node* next;
}
*head;

void Insert(int data, int nodePosition)
{
    struct node *temp = (struct node*) malloc(sizeof(struct node*)); 
    temp->data = data;
    temp->next = NULL;

    if (nodePosition == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }

    struct node *temp2 = head; 
    for (int i = 0; i < nodePosition - 2; i++) // minus 2 b/c we are starting w/ the head
    {
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;
    
    free(temp);
    
}

void Print()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
    
}

int main() 
{
   head = NULL; // the list is empty
   Insert(2, 1); //List: 2
   Insert(3, 2); //List: 2, 3
   Insert(4, 1); //List: 4, 2, 3
   Insert(5, 2); //List: 4, 5, 2, 3
   
   Print();
   


    
}