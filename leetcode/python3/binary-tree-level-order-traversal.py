#
# @lc app=leetcode id=102 lang=python
#
# [102] Binary Tree Level Order Traversal
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans = []
        q = []
        q.append(root)
        while q:
            tmp = []
            length = len(q)
            for i in range(length):
                node = q.pop(0)
                if node:
                    tmp.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if tmp:
                ans.append(tmp)
        return ans
        

