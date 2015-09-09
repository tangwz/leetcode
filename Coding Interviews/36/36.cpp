/**
 * 两个链表的第一个公共结点：http://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        // 找到链表差，短的先走。
        int len1 = ListLength(pHead1);
        int len2 = ListLength(pHead2);
        if(len1 > len2){
            pHead1 = walkStep(pHead1,len1 - len2);
        }else{
            pHead2 = walkStep(pHead2,len2 - len1);
        }
        while(pHead1 != NULL){
            if(pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
    
    int ListLength(ListNode *node){
        if(node == NULL) return 0;
        int sum = 1;
        while(node = node->next) sum++;
        return sum;
    }
    
    ListNode* walkStep(ListNode *node, int step){
        while(step--){
            node = node->next;
        }
        return node;
    }
};