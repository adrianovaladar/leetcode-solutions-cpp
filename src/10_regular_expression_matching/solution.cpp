class Solution {
    bool dfs(int i, int j, std::vector<std::vector<int>> &dp, const std::string &s, const std::string &p) {
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') dp[i][j] = (match && dfs(i + 1, j, dp, s, p)) || dfs(i, j + 2, dp, s, p);
        else dp[i][j] = match && dfs(i + 1, j + 1, dp, s, p);
        return dp[i][j];
    }
public:
    bool isMatch(string s, string p) {
        std::vector<std::vector<int>> dp (s.size() + 1, std::vector<int>(p.size() + 1, -1));
        bool answer =  dfs(0, 0, dp, s, p);
        return answer;
    }
};
