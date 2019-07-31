#
# @lc app=leetcode id=230 lang=python3
#
# [230] Kth Smallest Element in a BST
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        # 中序遍历，则按顺序输出
        def inorder_traversal(node):
            if not node:
                return None
            yield from inorder_traversal(node.left)
            yield node.val
            yield from inorder_traversal(node.right)

        gen = inorder_traversal(root)
        for _ in range(k-1):
            next(gen)
        return next(gen)
        

