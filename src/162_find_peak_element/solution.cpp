class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
    }
};
