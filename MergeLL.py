# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

start = ListNode(-0.1)
def insert_node(value):
    if(start.val == -0.1):
        
        start.val = value
    else:
        temp = start
        while(temp.next != None):
            temp = temp.next
        newNode = ListNode(value)
        temp.next = newNode
        
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        temp1 = l1
        temp12 = l1
        temp2 = l2
        temp22 = l2
        while(temp1.next != None):
            temp1 = temp1.next
        if(temp1.next == None):
            temp1.next = ListNode(-0.1)
        while(temp2.next != None):
            temp2 = temp2.next
        if(temp2.next == None):
            temp2.next = ListNode(-0.1) 
        while(temp1.next != None or temp2.next != None):
            if(temp1.val < temp2.val):
                insert_node(temp1.val)
                temp1 = temp1.next
            elif(temp1.val == temp2.val):
                insert_node(temp1.val)
                insert_node(temp1.val)
                temp1 = temp1.next
                temp2 = temp2.next
            else:
                insert_node(temp2.val)
                temp2 = temp2.next       
            
            
        