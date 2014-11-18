class TreeNode:
    def __init__(self, x):
        self.val = x      #         
        self.left = None
        self.right = None

class Solution:
    buff=[]
    result=[]
    count = 0
    n = 0 
    temp = []
    def bfs(self, buff):
    	if buff:
    		cur = buff.pop(0)

    		if cur.left is not None:
    			buff.append(cur.left)
    		if cur.right is not None:
    			buff.append(cur.right)
    		self.count += 1

    		if self.n == 0:
    			self.result.append(cur)
    		elif self.count>=2**(2*self.n-1) and self.count < 2**(2*n)-1:
    			self.temp.append(cur)
    			
    		elif self.count>=2**(2*self.n-2) and self.count < 2**(2*n-1):
    			result.append(cur)

    		elif self.count == 2**(2*self.n)-1 or self.count == 2**(2*self.n-1):
    			self.n += 1

    			if self.count == 2**(2*self.n)-1:
    				while self.temp:
    					self.result.append(self.temp.pop())
    				self.temp=[]

    		self.bfs(buff)

    def zigzagLevelOrder(self, root):
    	if root is not None:
    		self.buff.append(root)
    		self.bfs(self.buff)
    	return self.result
