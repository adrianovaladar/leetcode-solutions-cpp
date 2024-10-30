class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        std::sort(prices.begin(), prices.end());
        int sum = prices.at(0) + prices.at(1);
        return sum > money ? money : money - sum;
    }
};
