class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> mp;
        std::vector<int> answer;
        for (const auto &elem: nums) {
            mp[elem]++;
        }
        auto getMaxElement =  [](const auto &x, const auto &y) {return x.second < y.second;};
        for (int i {}; i < k; i++) {
            answer.emplace_back(std::max_element(mp.begin(), mp.end(), getMaxElement)->first);
            mp.erase(std::max_element(mp.begin(), mp.end(),getMaxElement));

        }
        return answer;
    }
};
