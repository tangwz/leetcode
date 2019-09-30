/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
class Node {
public:
    Node *left;
    Node *right;
    int leftnum;
    int rightnum;
    int repeat;
    int val;
    Node(int v) {
        val = v;
        repeat = 1;
        leftnum = 0;
        rightnum = 0;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        if (nums.size() == 0) return res;
        Node* root = new Node(nums[nums.size() - 1]);
        for (int i = nums.size()-2; i >= 0; i--) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }

    int insert(Node* root, int val) {
        if (val < root->val) {
            root->leftnum += 1;
            if (root->left) return insert(root->left, val);
            else {
                root->left = new Node(val);
                return 0;
            }
        }
        if (val == root->val) {
            root->repeat += 1;
            return root->leftnum;
        }
        if (val > root->val) {
            root->rightnum += 1;
            if (root->right) return root->leftnum + root->repeat + insert(root->right, val);
            else {
                root->right = new Node(val);
                return root->leftnum + root->repeat;
            }
        }
        return 0;
    }
};

