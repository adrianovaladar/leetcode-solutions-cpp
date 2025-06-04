class Solution {
    std::set<std::vector<int>> answer;
    void backtracking(int index, std::vector<int> &currentAnswer, const std::vector<int> &nums) {
        if (currentAnswer.size() > 1) answer.insert(currentAnswer);
        if (index == nums.size()) return;
        if (currentAnswer.empty() || currentAnswer.back() <= nums.at(index)) {
            currentAnswer.emplace_back(nums.at(index));
            backtracking(index + 1, currentAnswer, nums);
            currentAnswer.pop_back();
        }
        backtracking(index + 1, currentAnswer, nums);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        std::vector<int> currentAnswer;
        backtracking(0, currentAnswer, nums);
        return std::vector<std::vector<int>>(answer.begin(), answer.end());
    }
};
