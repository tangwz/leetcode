// Author : Tangwz
// Date   : 2015-02-2

/**********************************************************************************
*
*You are given two linked lists representing two non-negative numbers. The digits
are stored in reverse order and each of their nodes contain a single digit. Add the
two numbers and return it as a linked list.
*
*Tags: Linked List | Math
**********************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans = NULL,**t = &ans;
    int pre = 0;
    while(l1 != NULL || l2 != NULL){
        int x = getValueAndMove(l1);
        int y = getValueAndMove(l2);
        int ans_val = x + y + pre;
        pre=0;
        if(ans_val >= 10 ){
            pre = ans_val/10;
            ans_val = ans_val % 10;
        }
        ListNode *tmp = new ListNode(ans_val);
        /*while(ans->next != NULL){
            ans = ans->next;
        }*/
        *t = tmp;
        t = (&tmp->next);
    }
    if(pre > 0){
        ListNode *addone = new ListNode(pre%10);
        *t = addone;
    }

    return ans;
    }

    int getValueAndMove(ListNode* &l){
    int x = 0;
    if(l != NULL){
        x = l->val;
        l = l->next;
    }
    return x;
    }
};




