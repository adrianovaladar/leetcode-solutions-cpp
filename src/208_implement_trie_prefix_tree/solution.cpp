class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;    
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) return false;
            else cur = cur->children[c];
        }
        return cur->isEnd;

    }
    
    bool startsWith(string prefix) {
       TrieNode* cur = root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) return false;
            else cur = cur->children[c];    
        }
        return true;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
