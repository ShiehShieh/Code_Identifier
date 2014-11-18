class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def findLast(inlist, postlist):
	l = len(postlist)
	while l >= 1:
		if postlist[l-1] in inlist:
			return postlist[l-1]
		l -= 1
	return None
	
def createTree(inlist, postlist):
	if not inlist:
		return None	
	root = TreeNode(postlist[-1])
	index0 = inlist.index(postlist[-1])
	postlist = postlist[:-1]
	root.left = createTree(inlist[:index0], postlist[:index0])
	root.right= createTree(inlist[index0+1:], postlist[index0:-1])
	return root

def buildTree(inorder, postorder):
    if not inorder: return None
    root = TreeNode(postorder[-1])
    rootPos = inorder.index(postorder[-1])
    root.left = buildTree(inorder[ : rootPos], postorder[ : rootPos])
    root.right = buildTree(inorder[rootPos + 1 : ], postorder[rootPos : -1])
    return root

blist=[]
rlist = []
def getBFS(blist, ii):
	root = None
	if ii<len(blist):
		root = blist[ii]
	else:
		return
	if root is None:
		return
	else:
		if root.left is not None:
			blist.append(root.left)
			rlist.append(root.left.val)
		if root.right is not None:
			blist.append(root.right)
			rlist.append(root.right.val)
		if len(blist) > 0:
			ii += 1
			getBFS(blist, ii)
		
			
def bfs():
	ins = open("C:\Users\Administrator\Downloads\JudgeInput1.txt", 'r')
	ous = open("C:\Users\Administrator\Downloads\out1.txt", 'w')
	inlist=[]
	postlist=[]
	i = 0
	for line in ins:
		if i is 0:
			item = line[:-1].split(',')
			for num in item:
				inlist.append(num)
		if i is 1:
			item = line.split(',')
			for num in item:
				postlist.append(num)
		i += 1
	
	print inlist
	print postlist
	
	root = createTree(inlist, postlist)
	blist.append(root)
	rlist.append(root.val)
	ii = 0
	getBFS(blist, ii)

		
		
	print rlist
	for num in rlist:
		ous.write(str(num)+',')

	ins.close()
	ous.close()


if __name__ == "__main__":
	bfs()

	
