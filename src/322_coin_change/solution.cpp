class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp.at(0) = 0;
        for (int i {1}; i <= amount; i++) {
            for (int j {}; j < coins.size(); j++) {
                if (i >= coins.at(j)) dp.at(i) = std::min(dp.at(i), dp.at(i-coins.at(j)) + 1);
            }
        }
        return dp.at(amount) > amount ? -1 : dp.at(amount);
    }
};
