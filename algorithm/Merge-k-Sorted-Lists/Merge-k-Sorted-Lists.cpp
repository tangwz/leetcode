/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /*
     * keep merging the unmerged lists in lists until there is exactly one list remained.
     * do not merge lists[0] with lists[1], lists[2], ..., lists[n - 1] sequentially since that will cause TLE.
	 * merge the first two lists and then push it back to lists and erase the first two to avoid repeated merging.
    */
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        int n = lists.size();
        while(n > 1){
            for(int i = 0; i < n/2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[n - 1 - i]);
            n = (n + 1)/2;
        }
        return lists[0];
    }
    
private:
	/* This is the answer:https://leetcode.com/problems/merge-two-sorted-lists/ */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 == NULL || l2 == NULL) return NULL;
        ListNode *head = NULL;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        ListNode *cur = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 == NULL){
            cur->next = l2;
        }else{
            cur->next = l1;
        }
        
        return head;
    }
    
};