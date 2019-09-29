/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        while (root) {
            if (!root->left)
            {
                root = root->right;
            }
            else
            {
                TreeNode* pre = root->left;
                while (pre->right) pre = pre->right;
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};

