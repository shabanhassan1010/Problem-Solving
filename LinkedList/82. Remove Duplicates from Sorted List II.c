#include<stdio.h>

 struct ListNode 
 {
    int val;
    struct ListNode *next;
 };

struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode *temp, *prev;
    temp = head;
    prev = NULL;

    while (temp != NULL) 
    {
        // Check if the current node's value is equal to the next node's value
        if (temp->next != NULL && temp->val == temp->next->val) 
        {
            // Skip all nodes with the same value
            int duplicateVal = temp->val;
            while (temp != NULL && temp->val == duplicateVal) 
            {
                struct ListNode *toDelete = temp;
                temp = temp->next;
                free(toDelete);  // Free duplicate node
            }
            
            // If prev is NULL, we are at the beginning, update head
            if (prev == NULL) 
            {
                head = temp;
            } 
            else 
            {
                prev->next = temp;  // Skip all the duplicates
            }
        } 
        else 
        {
            // Move prev and temp forward when no duplicates
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}