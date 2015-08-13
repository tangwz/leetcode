/**
 * 反转链表：http://www.nowcoder.com/books/coding-interviews/75e878df47f24fdc9dc3e400ec6058ca?rp=1
 *
 * 输入一个链表，反转链表后，输出链表的所有元素。
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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* res = pHead;
        ListNode* post = res->next;
        while(post != NULL){
            // 头插法
            ListNode* tmp = post->next;
            post->next = res;
            res = post;
            post = tmp;
        }
        pHead->next = NULL;
         
        return res;
    }
};