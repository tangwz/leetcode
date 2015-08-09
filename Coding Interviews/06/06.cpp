/******************************************************************************
 * 从尾到头打印链表：http://www.nowcoder.com/books/coding-interviews/d0267f7f55b3412ba93bd35cfa8e8035?rp=1
 * 输入一个链表，从尾到头打印链表每个节点的值。
 */

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> res;
    vector<int> printListFromTailToHead(struct ListNode* head) {
        /* 使用堆栈：在这里使用堆栈比递归要好，因为递归可能会导致调用的层级很深，
         * 从而有可能导致函数调用栈溢出。
         *
         * 显示用栈的代码的鲁棒性更好。
        ListNode* pNode = head;
        stack<ListNode*> s;
        while(pNode != NULL){
            s.push(pNode);
            pNode = pNode->next;
        }
        while(!s.empty()){
            pNode = s.top();
            res.push_back(pNode->val);
            s.pop();
        }
        return res;
        */
        /* 使用递归 */
        if(head != NULL){
            if(head->next != NULL){
                printListFromTailToHead(head->next);
            }
            res.push_back(head->val);
        }
        return res;
    }
};