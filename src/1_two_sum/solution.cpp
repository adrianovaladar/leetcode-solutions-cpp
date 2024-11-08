class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (valueToIndex.count(complement)) {
                answer.emplace_back(valueToIndex[complement]);
                answer.emplace_back(i);
                break;
            }
            valueToIndex[nums[i]] = i;
        }
        return answer;
    }
};
