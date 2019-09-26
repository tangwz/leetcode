/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        if (len == 0) return NULL;

        int iroot = 0;
        for (iroot = 0; iroot < len; iroot++) {
            if (inorder[iroot] == postorder[len-1])
            {
                break;
            }
            
        }
        
        vector<int> ino_left, post_left;
        for (int i = 0; i < iroot; i++) {
            ino_left.push_back(inorder[i]);
            post_left.push_back(postorder[i]);
        }

        vector<int> ino_right, post_right;
        for (int i = iroot+1; i < len; i++) {
            ino_right.push_back(inorder[i]);
            post_right.push_back(postorder[i-1]);
        }

        TreeNode* root = new TreeNode(postorder[len-1]);
        root->left = buildTree(ino_left, post_left);
        root->right = buildTree(ino_right, post_right);
        return root;
    }
};

