class Solution {
    int dfs(int i, bool buying, std::vector<int> &prices) {
        if (i >= prices.size()) return 0;
        std::string key = to_string(i) + "-" + to_string(buying);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        int cooldown = dfs(i + 1, buying, prices);
        if (buying) {
            int buy = dfs(i +1, false, prices)  - prices[i];
            dp[key] = std::max(cooldown, buy);
        }
        else {
            int sell = dfs(i + 2, true, prices) + prices[i];
            dp[key] = std::max(cooldown, sell);
        }
        return dp[key];

    }
public:
    std::unordered_map<std::string, int> dp; 
    int maxProfit(vector<int>& prices) {
        int answer = dfs(0, true, prices);
        return answer;
    }
};
