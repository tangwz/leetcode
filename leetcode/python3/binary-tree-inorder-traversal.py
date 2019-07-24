#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # ans = []
        # def inorder_traversal(node):        
        #     if node:
        #         inorder_traversal(node.left)
        #         ans.append(node.val)
        #         inorder_traversal(node.right)
        # inorder_traversal(root)
        # return ans
        ans = []
        stack = []
        cur = root
        while cur or stack:
            if cur:
                stack.append(cur)
                cur = cur.left
                continue
            tmp = stack.pop()
            ans.append(tmp.val)
            cur = tmp.right
        return ans




