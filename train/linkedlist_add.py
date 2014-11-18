class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        add=0
        i=0
        j=0
        node = ListNode(0)
        first = ListNode(0)

        while l1 is not None and l2 is not None:
            a = l1.val + l2.val + add
            cur = ListNode(a%10)
            node.next = cur
            node = node.next
            if i == 0:
                first = node
            add = a/10
            l1 = l1.next
            l2 = l2.next
            print cur.val
            i += 1
        while l1 is not None:
            a = l1.val + add
            cur = ListNode(a%10)
            node.next = cur
            node = cur
            add = a/10
            l1 = l1.next
            print cur.val
        while l2 is not None:
            a = l2.val + add
            cur = ListNode(a%10)
            node.next = cur
            node = cur
            add = a/10
            l2 = l2.next
            print cur.val
        if add is not 0:
            cur = ListNode(add)
            node.next = cur
            print cur.val

        return first

if __name__ == "__main__":
    s1 = ListNode(5)
    s11 = ListNode(2)
    s12 = ListNode(3)
    s1.next = s11
    s11.next = s12

    s2 = ListNode(5)
    s21 = ListNode(3)
    s22 = ListNode(7)
    s2.next = s21
    s21.next = s22

    sol = Solution()
    l = sol.addTwoNumbers(s1, s2)

    print '--------------'
    while l is not None:
        print l.val
        l = l.next
