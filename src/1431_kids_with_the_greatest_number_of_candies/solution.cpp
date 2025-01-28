class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer;
        int maxCandies = *std::max_element(candies.begin(), candies.end());
        for (const auto &candy: candies) {
            bool isMax = candy + extraCandies >= maxCandies ? true : false;
            answer.emplace_back(isMax);
        }
        return answer;
    }
};
