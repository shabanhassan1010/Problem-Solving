#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *newNode;  
    newNode=(struct Node*)malloc(sizeof(struct Node));   //ceate new node 
    if(newNode == NULL)   // if new node == null so queue is full
        printf("Queue is FUll\n");
    else       
    {
        newNode->data=x;
        newNode->next=NULL;
    if(front==NULL)   // if this is the first node so i will set front and rear refer into newNode
        front=rear=newNode;
    else             // if this is not the first node..
    {
        rear->next=newNode;
        rear=newNode;
    }
    }
}

int dequeue()
{
    int x=-1;
    struct Node* newNode;
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->data;
        newNode=front;
        front=front->next;
        free(newNode);
    }
    return x;
}

