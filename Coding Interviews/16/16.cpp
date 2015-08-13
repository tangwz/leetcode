/**
 * 合并两个排序的链表：http://www.nowcoder.com/books/coding-interviews/d8b6b4358f774294a89de2a6ac4d9337?rp=1
 *
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    /* 掌握两种方法，很可能都会用到 */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
         
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        /* 迭代法
        ListNode* res = NULL;
        ListNode* cur = NULL;
         
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead2->val >= pHead1 ->val){
                if(res == NULL){
                    cur = res = pHead1;
                }else{
                    cur->next = pHead1;
                    cur = cur->next;
                }
                pHead1 = pHead1->next;
            }else{
                if(res == NULL){
                    cur = res = pHead2;
                }else{
                    cur->next = pHead2;
                    cur = cur->next;
                }
                pHead2 = pHead2->next;
            }    
        }
        if(pHead1 == NULL)
            cur->next = pHead2;
        if(pHead2 == NULL)
            cur->next = pHead1;
        return res;
        */
       
       /* 递归 */
        ListNode* res = NULL;
        if(pHead2->val >= pHead1->val){
            res = pHead1;
            res->next = Merge(pHead1->next, pHead2);
        }else{
            res = pHead2;
            res->next = Merge(pHead1, pHead2->next);
        }
        return res;
         
    }
};