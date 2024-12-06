
 struct ListNode {
      int value;
      struct ListNode *next;
  };
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode *previousNode , *modifiedNode = NULL;
    struct ListNode *walkNode = head;
    while(walkNode != NULL)
    {
        previousNode = modifiedNode;
        modifiedNode = walkNode;
        walkNode = walkNode->next;
        modifiedNode->next = previousNode;
    }
    head = modifiedNode;
    return  head;
}