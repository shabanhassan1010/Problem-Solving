#include<stdio.h>

 struct ListNode 
 {
    int val;
    struct ListNode *next;
 };

 void deleteNode(struct ListNode* node)      // he give me the node >>>> 5
{
    if(node == NULL || node->next  == NULL)  // at least must exist two nodes
    {
    return;
    }
    else
    {
        struct ListNode *temp = node->next;   // Hna el-temp hykon b3d node
        node->val = temp->val;                // take a copy from the temp  >> node = 1
        node->next = temp->next;             // hna el-node el next bet3ha bysawar 3la el-next 1>> bysawar 3la 9
        free(temp);
    } 
}