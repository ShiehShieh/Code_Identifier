class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	def reverseList(self, head):
		newhead = head
		pre = newhead
		curr = newhead.next
		pre.next = None

		while curr:
			temp = curr.next
			curr.next = pre
			pre = curr
			curr = temp
		if curr == None:
			return pre
		else:
			return curr
	
	def copyList(self, head):
		counter = 1
		new_head = ListNode(head.val)
		curr = head.next
		pre = new_head

		while curr:
			node = ListNode(curr.val)
			counter = counter + 1
			pre.next = node
			pre = node
			curr = curr.next
		return new_head, counter

	def reorderList(self, head):
		if head == None:
			return
		new_head, number = self.copyList(head)
		rev_head = self.reverseList(new_head)
		
		rhead = head
		index = 0
		while index<number:
			tmp1 = rhead.next
			tmp2 = rev_head.next

			rev_head.next = rhead.next
			index = index + 1

			rhead.next = rev_head
			index = index + 1
			
			if number%2==0 and index == number:
				rev_head.next = None
			elif number%2 != 0 and index + 1 == number:
				rev_head.next.next = None
				return 

			rev_head = tmp2
			rhead = tmp1

	
if __name__ == "__main__":
		t1 = ListNode(1)
		t2 = ListNode(2)
		t3 = ListNode(3)
		t4 = ListNode(4)
		t5 = ListNode(5)
		t6 = ListNode(6)
		t1.next = t2
		t2.next = t3

		sol = Solution()
		sol.reorderList(t1)
		while t1:
			print t1.val
			t1 = t1.next

