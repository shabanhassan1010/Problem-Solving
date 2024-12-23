#include<stdio.h>

 struct ListNode 
 {
    int val;
    struct ListNode *next;
 };

 void deleteNode(struct ListNode* node) 
{
    if(node == NULL || node->next  == NULL)
    {
    return;
    }
    else
    {
        struct ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        free(temp);
    } 
}