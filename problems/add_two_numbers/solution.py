# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum = l1.val + l2.val
        carry = sum // 10
        head = ListNode(sum % 10)
        node = head
        while l1.next or l2.next:
            if l1.next:
                l1 = l1.next
                a = l1.val
            else:
                a = 0
            if l2.next:
                l2 = l2.next
                b = l2.val
            else:
                b = 0
            sum = a + b + carry
            carry = sum // 10
            next_node = ListNode(sum % 10)
            node.next = next_node
            node = next_node
        if carry:
            node.next = ListNode(carry)
        return head
            
        