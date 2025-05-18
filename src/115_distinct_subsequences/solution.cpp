class Solution {
    int dfs(int i, int j, const std::string &s, const std::string &t, std::vector<std::vector<int>> &dp) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] =  dfs(i + 1, j, s, t, dp); 
        if (s[i] == t[j]) dp[i][j] += dfs(i + 1, j + 1, s, t, dp); 
        return dp[i][j];
    }

public:
    int numDistinct(string s, string t) {
        std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(t.size() + 1, -1));
        if (t.size() > s.size()) return 0;
        return dfs(0, 0, s, t, dp);
    }
};
