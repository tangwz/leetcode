/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pivot = head;
        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);
        ListNode* leftHead = left;
        ListNode* rightHead = right;
        ListNode* pivotHead = pivot;
        ListNode* cur = head->next;
        
        while (cur) {
            if (cur->val < pivot->val) {
                left->next = cur;
                left = left->next;
            } else if (cur->val > pivot->val) {
                right->next = cur;
                right = right->next;
            } else {
                pivot->next = cur;
                pivot = pivot->next;
            }
            cur = cur->next;
        }

        pivot->next = nullptr;
        left->next = nullptr;
        right->next = nullptr;
        left = sortList(leftHead->next);
        right = sortList(rightHead->next);
        pivot->next = right;
        ListNode* re = left;

        while (left && left->next) left = left->next;
        if (!left) re = pivotHead;
        else left->next = pivotHead;
        return re;

    }
};
// @lc code=end

