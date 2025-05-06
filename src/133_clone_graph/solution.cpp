/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    std::map<Node*, Node*> mapNodes;
    Node* dfs(Node* node) {
        if (node == nullptr) return nullptr;
        if (mapNodes.find(node) != mapNodes.end()) return mapNodes[node];
        Node *newNode = new Node(node->val);
        mapNodes[node] = newNode;
        for (const auto &neighbor: node->neighbors) {
            newNode->neighbors.emplace_back(dfs(neighbor));
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
