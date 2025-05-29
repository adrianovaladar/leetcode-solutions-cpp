class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        std::vector<int> answer;
        for (int i {} ; i < nums.size() ; i++) {
            answer.emplace_back(nums.at(nums.at(i)));
        }
        return answer;
    }
};
