class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> vec(s.size() + 1, false);
        vec.back() = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (const auto &word: wordDict) {
                if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) vec.at(i) = vec.at(i + word.size());
                if (vec.at(i)) break;
            }
        }
        return vec.at(0);
    }
};
