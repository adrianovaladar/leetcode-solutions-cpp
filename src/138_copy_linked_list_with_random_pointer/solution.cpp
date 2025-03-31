/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    std::unordered_map<Node*,Node*>mapNodes;
public:
    Node* copyRandomList(Node* head, int count = 0) {
        if (head == nullptr) return nullptr;
        Node *copyHead = new Node(head->val);
        mapNodes[head] = copyHead;
        copyHead->next = copyRandomList(head->next, count + 1);
        copyHead->random = mapNodes[head->random];
        return copyHead;
    }
};
