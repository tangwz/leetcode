/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return ans;
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* root, int sum) {
        path.push_back(root->val);
        sum -= root->val;

        if (!root->left && !root->right) {
            if (sum == 0)
            {
                ans.push_back(path);
            }
        }
        else
        {
            if (root->left) dfs(root->left, sum);
            if (root->right) dfs(root->right, sum);
        }

        path.pop_back();
    }

};

