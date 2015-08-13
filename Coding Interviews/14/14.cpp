/**
 * 链表中倒数第k个结点： http://www.nowcoder.com/books/coding-interviews/529d3ae5a407492994ad2a246518148a?rp=1
 *
 * 输入一个链表，输出该链表中倒数第k个结点。
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
    /* O(N)，使用两个指针来计算 */
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0)
            return NULL;
        ListNode* front = pListHead;
        for(int i = 1; i < k; ++i){
            front = front->next;
            if(front == NULL) return NULL;
        }
        ListNode* node = pListHead;
        while(front->next != NULL){
            front = front->next;
            node = node->next;
        }
        return node;
    }
};