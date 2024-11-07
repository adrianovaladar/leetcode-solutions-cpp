class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        auto minIt = std::min_element(nums.begin(), nums.end());
        auto maxIt = std::max_element(nums.begin(), nums.end());
        if (minIt == nums.end() && maxIt == nums.end()) return -1;
        for(const auto &num: nums) {
            if(num > *minIt && num < *maxIt)
                return num;
        }
        return -1;
    }
};
