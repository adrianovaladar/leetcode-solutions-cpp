class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                string word = q.front(); q.pop();
                if (word == endWord) return steps;
                for (int j = 0; j < word.size(); ++j) {
                    string temp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[j] = c;
                        if (dict.find(temp) != dict.end()) {
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
