#
# @lc app=leetcode id=144 lang=python3
#
# [144] Binary Tree Preorder Traversal
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        # ans = []
        # def traversal(root):
        #     if root:
        #         ans.append(root.val)
        #         traversal(root.left)
        #         traversal(root.right)
        # traversal(root)
        # return ans
        ans = []
        stack = []
        while root or stack:
            if root:
                ans.append(root.val)
                if root.right:
                    stack.append(root.right)
                root = root.left
            else:
                root = stack.pop()
        return ans

