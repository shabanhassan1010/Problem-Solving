#include <stdio.h>

struct Node 
{ 
    int data; 
    struct Node *next; 
} *first = NULL, *head = NULL;

int main() 
{
   int list[]={2,3,4,5,6};
   create(list,5);
  
   return 0;
}

void Display(struct Node *temp)
{
 do
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }while(temp!=first);
    printf("\n");
}