class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
        for (int i {m-2}; i >= 0; i--) {
            for (int j{n-2}; j >= 0; j--) {
                dp.at(i).at(j) = dp.at(i+1).at(j) + dp.at(i).at(j + 1);
            }
        }
        return dp.at(0).at(0);
    }
};
