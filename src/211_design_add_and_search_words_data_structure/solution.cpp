class TrieNode {
public:    
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class WordDictionary {
    TrieNode* root = new TrieNode;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(const auto &character: word) {
            if (node->children.find(character) == node->children.end()) {
                node->children[character] = new TrieNode();
            }
            node = node->children[character];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

private:
    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (index == word.length()) return node->isEnd;
        char currentChar = word[index];
        if (currentChar == '.') {
            for (auto& child : node->children) {
                if (searchHelper(word, index + 1, child.second)) return true;
            }
            return false;
        } else {
            if (node->children.find(currentChar) == node->children.end()) return false;
            return searchHelper(word, index + 1, node->children[currentChar]);
        }
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
