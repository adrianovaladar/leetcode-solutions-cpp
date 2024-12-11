class Solution {
    void backtracking(std::vector<string> &answer, std::string &s, int open, int close, const int &n) {
        if (close == n && close == open) answer.emplace_back(s);
        if (open < n) {
            s += "(";
            backtracking(answer, s, open+1, close, n);
            s.pop_back();      
        }
        if (open > close) {
            s += ")";
            backtracking(answer, s, open, close+1, n);
            s.pop_back();      
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> answer;
        int open {};
        int close {};
        std::string s;
        backtracking(answer, s, open, close, n);
        return answer;
    }
};
