
  #include <iostream>
  using namespace std;

  struct ListNode
  { 
      int val;
      ListNode *next;
  };


ListNode *head = NULL;
ListNode **final_ans = &head;




void insert_ll(int number)
{
    if(head == NULL)
    {
        ListNode *temp = new ListNode;
        temp -> val = number;
        temp -> next = NULL;
        head = temp;
        
    }
    else
    {
       ListNode *temp = new ListNode;
       temp -> val = number;
       temp -> next = NULL;
       head -> next = temp;
       head = head -> next;
    }
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        while(l1 != NULL and l2!= NULL)
        {
            if(l1 -> value < l2 -> value)
            {
                insert_ll(l1->value);
                l1 = l1 -> next;
            }
            else
            {
                insert_ll(l2->value);
                l2 = l2->next;
            }
            if(l1 != NULL)
            {
                while(l1 != NULL)
                {
                    insert_ll(l1 -> value);
                    l1 = l1 -> next;
                }
            }
            if(l2 != NULL)
            {
                while(l2 != NULL)
                {
                    insert_ll(l2 -> value);
                    l2 = l2 -> next;
                }
            }
        }
    }
};



int main()
{
    

    return 0;
}
