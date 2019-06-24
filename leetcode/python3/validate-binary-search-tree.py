#
# @lc app=leetcode id=98 lang=python
#
# [98] Validate Binary Search Tree
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root: TreeNode) -> bool:
        self.pre = None
        def foo(root):
            if not root:
                return True

            if not foo(root.left):
                return False

            if self.pre and self.pre.val >= root.val:
                return False
            self.pre = root

            return foo(root.right)
        
        return foo(root)

