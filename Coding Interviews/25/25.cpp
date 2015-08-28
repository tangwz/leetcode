/**
 * 复杂链表的复制：http://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?rp=2&ru=/ta/coding-interviews
 *
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
 * 
 */
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;
        RandomListNode* pRes = new RandomListNode(pHead->label);
        RandomListNode* pNode = pRes;
        RandomListNode* pOld = pHead->next;
        map<RandomListNode*, RandomListNode*> link;
        link[pHead] = pRes;
        
        // 第一遍next
        while(pOld){
            pNode->next = new RandomListNode(pOld->label);
            link[pOld] = pNode->next;
            pOld = pOld->next;
        	pNode = pNode->next;
        }
        
        pOld = pHead;
        pNode = pRes;
        while(pOld){
            pNode->random = link[pOld->random];
            pNode = pNode->next;
        	pOld = pOld->next;
        }
        
        return pRes;
    }
};