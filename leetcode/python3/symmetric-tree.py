#
# @lc app=leetcode id=101 lang=python
#
# [101] Symmetric Tree
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # def is_symmetric(left, right):
        #     if left and right:
        #         if left.val != right.val:
        #             return False
        #     elif not left and not right:
        #         return True
        #     else:
        #         return False
            
        #     return is_symmetric(left.right, right.left) and is_symmetric(left.left, right.right)
        
        # if not root:
        #     return True
        # return is_symmetric(root.left, root.right)

        if not root:
            return True
        q = []
        q.append(root.left)
        q.append(root.right)
        while q:
            t1 = q.pop(0)
            t2 = q.pop(0)
            if not t1 and not t2:
                continue
            if not t1 or not t2:
                return False
            if t1.val != t2.val:
                return False
            q.append(t1.left)
            q.append(t2.right)
            q.append(t1.right)
            q.append(t2.left)
        return True

