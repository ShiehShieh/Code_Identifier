class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    mylist = []
    
    def postorderTraversal(self, root):
        
        if root != None:
            left = root.left
            if left != None:
                self.postorderTraversal(left)
            right = root.right
            if right != None:
                self.postorderTraversal(right)
            self.mylist.append(root.val)
        
        return self.mylist

    def posttest(self, root):
       mylist1 = []
       nodelist = []
       mystack= []
       node = TreeNode(0)
       
       if root == None:
           return mylist

       nodelist.append(root)

       while nodelist:
           node = nodelist.pop()
           if node.left != None:
               nodelist.append(node.left)
           if node.right != None:
               nodelist.append(node.right)
           mystack.append(node)

       while mystack:
           mylist1.append(mystack.pop().val)
           
       return mylist1
    def preordertest(self, root):
       mylist1 = []
       nodelist = []
       mystack= []
       node = TreeNode(0)
       
       if root == None:
           return mylist1

       nodelist.append(root)
       while nodelist:
           node = nodelist.pop()
           mylist1.append(node.val)
           if node.right != None:
               nodelist.append(node.right)
           if node.left != None:
               nodelist.append(node.left)
           
       return mylist1

if __name__ == "__main__":
	t1 = TreeNode(1)
	t2 = TreeNode(2)
	t3 = TreeNode(3)
	t4 = TreeNode(4)
	t5 = TreeNode(5)
	t1.left = t2
	t1.right = t3
	t2.left = t4
	t2.right = t5

	t6 = TreeNode(1)
	
	sol = Solution()
	sol1 = Solution()
	mylist2 = sol1.posttest(t1)
	mylist3 = sol.preordertest(t1)
	print (mylist3)
