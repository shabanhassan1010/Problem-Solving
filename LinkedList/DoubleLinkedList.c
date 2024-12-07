#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;

void create(int arr[], int n) 
{
    struct Node *temp, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->prev = head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++) // Start from 1
    { 
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;  // Sets the next pointer of the new node to NULL (since it's the last node for now).
        temp->prev = last;  // Sets the prev pointer of the new node to point to the last node (the previous node).
        last->next = temp; // Updates the next pointer of the last node to point to the new node, linking the two
        last = temp;      // Updates the last pointer to point to the new node, making it the new last node.
    }
}

void Display(struct Node *temp) 
{
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int Length(struct Node *temp) 
{
    int count = 0;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void insert(struct Node *temp, int index, int value) 
{
    struct Node *newNode;

    // Check if the index is valid
    if (index < 0 || index > Length(temp)) {
        printf("Invalid index\n");
        return;
    }

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    // Case 1: Insert at the beginning
    if (index == 0) {
        newNode->prev = NULL;
        newNode->next = temp;
        if (temp != NULL) temp->prev = newNode;
        head = newNode; // Update the global `first` pointer
        return;
    }

    // Case 2: Insert at a specific position
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Insert the new node
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)     //If temp->next is not NULL, it means there is a node after temp
    temp->next->prev = newNode; //temp->next: This refers to the node that currently comes after temp in the list.
    temp->next = newNode;
}

int Delete(struct Node *temp , int index)
{
    struct Node *deletedNode;
    int value;
    if(index < 0 || index > Length(temp))
    return -1;
    if(index == 1)
    {
        deletedNode = head;  
        value = head->data;  // take data
        head = head->next;   // head move to second node
        if(head!= NULL)
        {
        head->prev = NULL;   // hna 8alet el-head don't refer for any node
        }
        free(deletedNode);
    }
    else
    {
        for (int i = 0; i < index - 1 && temp != NULL; i++) 
        {
        deletedNode = deletedNode->next;
        }
        deletedNode->prev->next = deletedNode->next;
        if(deletedNode->next != NULL)
        {
            deletedNode->next->prev = deletedNode->prev;
        }
        free(deletedNode);
    }
    return value;
}


int main() 
{
    int list[] = {2, 3, 4, 5, 6 , 9};
    create(list, 6); 
    printf("Create Linked List: ");

    Display(head); 
    printf("Length of the list: %d\n", Length(head)); 

    insert(head,3, 8);
    Display(head); 

    Delete(head , 1);
    Delete(head , 3);
    Display(head); 

    return 0;
}
