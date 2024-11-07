class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        return nums[nums.size() / 2];
    }
};
