/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MAX;
        if (root->left) ans = min(ans, minDepth(root->left) + 1);
        if (root->right) ans = min(ans, minDepth(root->right) + 1);
        if (ans == INT_MAX) ans = 1;
        return ans;
    }
};

