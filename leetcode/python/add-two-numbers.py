# coding: utf-8

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    """
        Time complexity : O(n)
        Space complexity: O(n)
    """
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p = ListNode(-1)
        res = p
        val = 0
        while l1 or l2 or val:
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            p.next = ListNode(val % 10)
            val = val / 10
            p = p.next
        return res.next



if __name__ == '__main__':
    l1 = ListNode(2)
    l1_n = ListNode(4)
    l1_nn = ListNode(3)

    l1.next = l1_n
    l1_n.next = l1_nn

    l2 = ListNode(5)
    l2_n = ListNode(6)
    l2_nn = ListNode(4)
    l2.next = l2_n
    l2_n.next = l2_nn

    s = Solution()
    ret = s.addTwoNumbers(l1, l2)
    assert ret.val == 7
    assert ret.next.val == 0
    assert ret.next.next.val == 8
    print "test passed"