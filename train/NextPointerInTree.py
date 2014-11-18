class Solution:
    def connect(self, root):
		if root == None:
			return 
		if root.left == None and root.right == None:
			return
		
		last = root.right 
		if last == None:
			last = root.left

		first = root.next

		while True:
		    if first == None:
		    	break
		    if first.left != None:
		        last.next = first.left
		        break
		    if first.right != None:
		        last.next = first.right
		        break

		    first = first.next

		if root.left != None and root.right != None:
		        root.left.next = root.right

		connect(root.right)
		connect(root.left)
