/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        while (cur)
        {
            Node* dummy = new Node(0);
            dummy->next = NULL;
            Node* tail = dummy;
            while (cur)
            {
                if (cur->left)
                {
                    tail->next = cur->left;
                    tail = tail->next;
                }
                if (cur->right)
                {
                    tail->next = cur->right;
                    tail = tail->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        return root;
    }
};

