/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* node, int v) {
        if (!node) return;
        int sum = v * 10 + node->val;
        dfs(node->left, sum);
        dfs(node->right, sum);
        if (!node->left && !node->right) ans += sum;
    }
};
// @lc code=end

