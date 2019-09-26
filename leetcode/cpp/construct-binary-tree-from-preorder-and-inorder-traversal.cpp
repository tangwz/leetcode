/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();

        if (len == 0) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        int iroot = 0;
        for (int i = 0; i < len; i++) {
            if (inorder[i] == preorder[0]) {
                iroot = i;
                break;
            }
        }

        vector<int> pre_left, ino_left;
        for (int i = 0; i < iroot; i++) {
            pre_left.push_back(preorder[i+1]);
            ino_left.push_back(inorder[i]);
        }

        vector<int> pre_right, ino_right;
        for (int i = iroot+1; i < len; i++) {
            pre_right.push_back(preorder[i]);
            ino_right.push_back(inorder[i]);
        }

        root->left = buildTree(pre_left, ino_left);
        root->right = buildTree(pre_right, ino_right);
        return root;
    }
};

