class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            if (valueToIndex.count(complement)) {
                answer.emplace_back(valueToIndex[complement] + 1);
                answer.emplace_back(i + 1);
                break;
            }
            valueToIndex[numbers[i]] = i;
        }
        return answer;
    }
};
