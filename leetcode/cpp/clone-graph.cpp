/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.count(node)) return visited[node];
        Node* res = new Node(node->val);
        visited[node] = res;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (node->neighbors[i]) res->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return res;
    }
};

