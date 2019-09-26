/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        int l = 0;
        for (auto i = head; i; i=i->next) l++;

        int mid = l/2;
        ListNode* p = head;
        for (int i = 0; i < mid; i++) p = p->next;
        TreeNode* root = new TreeNode(p->val);
        root->right = sortedListToBST(p->next);
        if (mid)
        {
            p = head;
            for (int i = 0; i < mid-1; i++) p = p->next;
            p->next = NULL;
            root->left = sortedListToBST(head);
        }
        
        return root;
    }
};

