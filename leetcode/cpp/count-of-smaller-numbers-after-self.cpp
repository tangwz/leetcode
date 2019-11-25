/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
// class Node {
// public:
//     Node *left;
//     Node *right;
//     int leftnum;
//     int rightnum;
//     int repeat;
//     int val;
//     Node(int v) {
//         val = v;
//         repeat = 1;
//         leftnum = 0;
//         rightnum = 0;
//         left = nullptr;
//         right = nullptr;
//     }
// };

// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> res(nums.size(), 0);
//         if (nums.size() == 0) return res;
//         Node* root = new Node(nums[nums.size() - 1]);
//         for (int i = nums.size()-2; i >= 0; i--) {
//             res[i] = insert(root, nums[i]);
//         }
//         return res;
//     }

//     int insert(Node* root, int val) {
//         if (val < root->val) {
//             root->leftnum += 1;
//             if (root->left) return insert(root->left, val);
//             else {
//                 root->left = new Node(val);
//                 return 0;
//             }
//         }
//         if (val == root->val) {
//             root->repeat += 1;
//             return root->leftnum;
//         }
//         if (val > root->val) {
//             root->rightnum += 1;
//             if (root->right) return root->leftnum + root->repeat + insert(root->right, val);
//             else {
//                 root->right = new Node(val);
//                 return root->leftnum + root->repeat;
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) p[i] = make_pair(i, nums[i]);
        mergeSort(p, ans, 0, n);
        return ans;
    }

    void mergeSort(vector<pair<int, int>>& p, vector<int>& ans, int left, int right) {
        if (left + 1 < right) {
            int mid = left + right >> 1;
            mergeSort(p, ans, left, mid);
            mergeSort(p, ans, mid, right);
            merge(p, ans, left, mid, right);
        }
        return;
    }

    void merge(vector<pair<int, int>>& p, vector<int>& ans, int left, int mid, int right) {
        auto it_left = p.begin() + left;
        auto it_mid = p.begin() + mid;
        auto it_right = p.begin() + right;

        vector<pair<int, int>> l(it_left, it_mid), r(it_mid, it_right);
        int i = 0, j = 0, k = 0;
        while (i < l.size() && j < r.size()) {
            if (l[i].second <= r[j].second) {
                ans[l[i].first] += j;
                p[left+k] = l[i];
                ++i;
                ++k;
            } else {
                p[left+k] = r[j];
                ++j;
                ++k;
            }
        }

        while (i < l.size()) {
            ans[l[i].first] += j;
            p[left+k] = l[i];
            ++i;
            ++k;
        }

        while (j < r.size()) {
            p[left+k] = r[j];
            ++j;
            ++k;            
        }

    }
};

