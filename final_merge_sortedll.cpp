
 
  struct ListNode {
      int val;
      ListNode *next;
      
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *cur = nullptr;
        ListNode **head = &cur;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                cur -> next = l1;
                l1 = l1->next;
            }
            else
            {
                cur -> next = l2;
                l2 = l2 -> next;
            }

            cur = cur -> next;  // imp
        }
        if(l1)
        {
            cur -> next = l1;
            l1 = nullptr;
        }
        else if(l2)
        {
            cur -> next = l2;
            l2 = nullptr;
        }

        cur = *(head);
        return cur;
        
    }
};