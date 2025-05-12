class Solution {
    std::vector<std::vector<int>> directions = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
    int dfs(int i, int j, int previousValue, const std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &dp) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix.at(0).size() || (matrix[i][j] <= previousValue && previousValue != -1)) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        for (const auto &direction: directions) {
            dp[i][j] = std::max(dp[i][j], 1 + dfs(i + direction[0], j + direction[1], matrix[i][j], matrix, dp));
        }
        return dp[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix.at(0).size(), -1));
        int answer {};
        for (int i{}; i < matrix.size(); i++) {
            for (int j {}; j < matrix.at(0).size(); j++) {
                answer = std::max(answer, dfs(i, j, -1, matrix, dp));
            }
        }
        return answer;
    }
};
