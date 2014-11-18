class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def preOrder(self, root, root1):
        if root  == root1 == None:
            return True
        elif not (root and root1):
            return False
        else:
            if root.val != root1.val:
                return False
            
            if root.left is None and root.right is None and root1.left is None and root1.right is None:
                print root.val, root1.val
                if root.val == root1.val:
                    return True       
                
            return self.preOrder(root.left, root1.left) and self.preOrder(root.right, root1.right)
                
        
    def isSameTree(self, p, q):
        if  p == q == None:
            return True
        elif not (p and q):
            return False
        else:
            return self.preOrder(p, q)

if __name__=='__main__':
    t = TreeNode(1)
    t1 = TreeNode(3)
    t2 = TreeNode(2)

    t10 = TreeNode(1)
    t11 = TreeNode(3)
    t12 = TreeNode(2)

    t.right = t2
    t.left = t1
    t10.right = t12
    t10.left = t11

    sol = Solution()
    print sol.isSameTree(t, t10)
