class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> answer;
        int value {1};
        for (int i {}; i < nums.size(); i++) {
            answer.emplace_back(value);
            value *= nums.at(i);
        }
        value = 1;
        for (int i = nums.size()-1; i >=0; i--) {
            answer.at(i) *= value;
            value *= nums.at(i);
        }
        return answer;
    }
};
