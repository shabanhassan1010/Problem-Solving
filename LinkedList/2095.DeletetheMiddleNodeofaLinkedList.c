struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL) 
    return NULL; 

    struct ListNode *q = NULL, *temp = head;
    int count = 0, mid;

    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }

    mid = count / 2; // i use this syntax because i do not want go after the center of linkedlist
    temp = head;

    for (int i = 0; i < mid; i++) 
    {
        q = temp;       
        temp = temp->next;
    }

    q->next = temp->next; 
    free(temp);
    return head;
}