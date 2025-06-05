/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void dfs(Node *root, int level, int &count) {
        if (root == nullptr) return;
        for (const auto & child : root->children) {
            dfs(child, level + 1, count);
        }
        count = std::max(level, count);
    }
public:
    int maxDepth(Node* root) {
        int count = 0;
        dfs(root, 1, count);
        return count;
    }
};
