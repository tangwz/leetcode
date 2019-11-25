/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        vector<int> ans;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }

            if (!s.empty()) {
                p = s.top();
                ans.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
// @lc code=end

