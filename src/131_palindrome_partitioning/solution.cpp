class Solution {
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }
    void backtracking(int start, std::vector<std::string> &currentAnswer, std::vector<std::vector<std::string>> &answer, const std::string &s) {
        if (start >= s.length()) answer.push_back(currentAnswer);
        for (int end {start}; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                currentAnswer.emplace_back(s.substr(start, end - start + 1));
                backtracking(end + 1, currentAnswer, answer, s);
                currentAnswer.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> answer;
        std::vector<std::string> currentAnswer;
        backtracking(0, currentAnswer, answer, s);
        return answer;
    }
};
