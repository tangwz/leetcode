#
# @lc app=leetcode id=145 lang=python3
#
# [145] Binary Tree Postorder Traversal
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # ans = []
        # def traversal(root):
        #     if root:
        #         traversal(root.left)
        #         traversal(root.right)
        #         ans.append(root.val)
        # traversal(root)
        # return ans

        # if not root:
        #     return []
        # ans, stack = [], [root]
        # while stack:
        #     root = stack.pop()
        #     ans.append(root.val)

        #     if root.left:
        #         stack.append(root.left)
        #     if root.right:
        #         stack.append(root.right)
            
        # return ans[::-1]


        ans = []
        stack = []
        last = None
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            
            root = stack[-1]
            if not root.right or root.right == last:
                ans.append(root.val)
                stack.pop()
                last = root
                root = None
            else:
                root = root.right
        return ans

