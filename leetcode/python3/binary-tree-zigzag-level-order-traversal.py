#
# @lc app=leetcode id=103 lang=python3
#
# [103] Binary Tree Zigzag Level Order Traversal
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        ans = []
        depth = 1
        q = [root]
        while q:
            tmp = []
            length = len(q)
            for i in range(length):
                node = q.pop(0)
                if node:
                    tmp.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if not tmp:
                continue
            if depth % 2 == 0:
                ans.append(tmp[::-1])
            else:
                ans.append(tmp)
            depth += 1
        return ans

