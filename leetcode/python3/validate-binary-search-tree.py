#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        # def check(node, lower=float('-inf'), upper=float('inf')):
        #     if not node:
        #         return True

        #     val = node.val
        #     if val <= lower or val >= upper:
        #         return False

        #     if not check(node.left, lower, val):
        #         return False
        #     if not check(node.right, val, upper):
        #         return False
        #     return True
        # return check(root)

        stack, vmin = [], float('-inf')

        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            
            root = stack.pop()
            if root.val <= vmin:
                return False
            vmin = root.val
            root = root.right
        return True





