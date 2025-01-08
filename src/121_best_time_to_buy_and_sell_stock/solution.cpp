class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice {INT_MAX};
        int maxProfit {};
        for (int i {}; i < prices.size(); i++) {
            if (prices.at(i) < minPrice) {
                minPrice = prices.at(i);
            } else if (prices.at(i) - minPrice > maxProfit) {
                maxProfit = prices.at(i) - minPrice;
            }
        }
        return maxProfit;
    }
};
