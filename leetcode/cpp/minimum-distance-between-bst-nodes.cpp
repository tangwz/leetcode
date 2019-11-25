/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    int ans = INT_MAX, prev = -1;
    int minDiffInBST(TreeNode* root) {
        if (root) {
            if (root->left) minDiffInBST(root->left);
            if (prev > 0) ans = min(ans, root->val-prev);
            prev = root->val;
            if (root->right) minDiffInBST(root->right);
        }
        return ans;
    }
};
// @lc code=end

