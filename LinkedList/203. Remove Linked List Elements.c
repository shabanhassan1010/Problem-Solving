#include<stdio.h>

 struct ListNode 
 {
    int val;
    struct ListNode *next;
 };


struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode *temp , *q;
    temp = head , q = NULL;
    while (temp != NULL && temp->val == val) // check if head node.value  == value
    {
        temp = temp->next;                // Move the head pointer to the next node
    }
    head = temp;  // Update head to the new starting node

    while(temp != NULL) // Traverse the list and remove nodes
    {
        q = temp;  // set temp fe q
        temp = temp->next; // temp walk to the next node
        if(temp->val == val)  // and check if ture
        {
            q->next = temp->next;  // q refre to the node which temp refer it
            temp = temp->next;     // temp walk to the next node
        }
    }
    return head;
}