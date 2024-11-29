class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int,int> numbers;
        for (int i {}; i < nums.size(); i++) {
            if (numbers.find(nums[i]) != numbers.end() && i - numbers[nums[i]] <= k) {
                return true;
            }
            numbers[nums[i]] = i;
        }
        return false;
    }
};
