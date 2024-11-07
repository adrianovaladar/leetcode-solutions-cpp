class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int,int> occurrencesNums;
        for (auto n: nums)
            occurrencesNums[n]++;
        auto it = std::find_if(occurrencesNums.begin(), occurrencesNums.end(),
                               [](const auto& pair) { return pair.second == 1; });
        return it != occurrencesNums.end() ? it->first : -1;
    }
};
