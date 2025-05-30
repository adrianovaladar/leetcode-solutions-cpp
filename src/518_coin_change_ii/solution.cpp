class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<std::vector<uint>> dp(coins.size(), std::vector<uint>(amount + 1, 0));
        for (int i {}; i < dp.size(); i++) {
            dp.at(i).back() = 1;
        }
        for (int i = dp.size() - 1; i >= 0; i--) {
            for (int j = dp.at(0).size() - 2; j >= 0; j--) {
                if (j + coins.at(i) <= dp.at(0).size() - 1) dp.at(i).at(j) += dp.at(i).at(j + coins.at(i));
                if (i + 1 < dp.size()) dp.at(i).at(j) += dp.at(i + 1).at(j);
            }
        }
        return dp.at(0).at(0);
    }
};
