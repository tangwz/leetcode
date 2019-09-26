/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int d = abs(dfs(root->left)-dfs(root->right));
        return d <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};

