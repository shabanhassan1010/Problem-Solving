/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int value;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
      int value;
      struct ListNode *next;
  };
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode *prev = NULL;      // Tracks the previous node
    struct ListNode *temp = head;     // Tracks the current node
    struct ListNode *next = NULL;
    while (temp != NULL) {
        next = temp->next;  
        temp->next = prev;  // Reverse the next pointer
        prev = temp;        
        temp = next;        
    } 
   return prev; // New head of the reversed list   
}