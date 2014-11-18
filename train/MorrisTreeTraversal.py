
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:

            
    def recoverTree(self, root):
        if root is None:
            return root
        else:
            current = root
            ptr = None
            prev = None
            prev1 = None
            cur1 = None
            prev2 = None
            cur2 = None
            while current is not None:
                if current.left is None:
                    prev = current
                    current = current.right
                else:
                    ptr = current.left
                    while ptr.right is not None and ptr.right is not current:
                        ptr = ptr.right
                    if ptr.right is None:
                        ptr.right = current
                        current = current.left
                    else:
                        ptr.right = None
                        prev = current
                        current = current.right
                
                if prev is not None and current is not None and prev.val > current.val:
                    if prev1 is None:
                        prev1 = prev
                        cur1 = current
                    else:
                        prev2 = prev
                        cur2 = current
            if prev1 is not None and cur2 is not None:
                prev1.val, cur2.val = cur2.val, prev1.val
            else:
                prev1.val, cur1.val = cur1.val, prev1.val
            
    
        
        
if __name__ == '__main__':
    t = TreeNode(1)
    t1 = TreeNode(3)
    t2 = TreeNode(2)
    t.left = t1
    t.right = t2
    
    sol = Solution()
    sol.recoverTree(t)
    pass
