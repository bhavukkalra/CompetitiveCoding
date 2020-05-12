# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def LengthList(obj):
    length = 1
    while(obj.next != None):
        obj = obj.next
        length = length + 1
    return length 
       


    
    
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        l = LengthList(head)
        if(l == 1):
            return head
        for i in range(1,int(l/2) + 1):
            head = head.next
        return head        
                   

            
          
        