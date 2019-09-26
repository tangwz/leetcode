/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(TreeNode* node, int level, vector<vector<int>>& res) {
        if (node != NULL) {
            if (res.size() <= level)
            {
                res.push_back(vector<int>());
            }
            res[level].push_back(node->val);
        }
        else
        {
            return;
        }

        dfs(node->left, level+1, res);
        dfs(node->right, level+1, res);
    }
};

