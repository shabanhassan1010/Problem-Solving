#include<stdio.h>

 struct ListNode 
 {
    int val;
    struct ListNode *next;
 };



struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode *temp , *q;
    temp = head;
    q = temp != NULL ? temp->next : NULL; //  q = temp->next;  Initialize q to the node after temp
    while(q != NULL)
    {
        if (temp->val != q->val)
        {
            temp = q ;
            q = q->next;
        }
        else
        {
            temp->next = q->next;
            free(q );
            q = temp->next;
        }
    }
    return head;
}


