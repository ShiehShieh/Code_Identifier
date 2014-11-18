class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    depth = 0
    count=0
    def dfs(self, root):
    	self.count += 1
    	if root.left is None and root.right is None:
    		if self.count > self.depth:
    			self.depth = self.count
    	else:
    		if root.left is not None:
    			self.dfs(root.left)
    			count -= 1
    		if root.right is not None:
    			self.dfs(root.right)
    			count -= 1


    def maxDepth(self, root):
    	if root is not None:
    		self.dfs(root)
    		return self.depth
    	else:
    		return 0;


        
