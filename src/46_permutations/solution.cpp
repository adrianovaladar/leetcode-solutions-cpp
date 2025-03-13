class Solution {
    void backtracking(int index, vector<int>& nums, std::vector<int> &current, std::vector<std::vector<int>> &answer) {
        if (current.size() == nums.size()) answer.emplace_back(current);
        for (const auto & num: nums) {
            if (std::find(current.begin(), current.end(), num) != current.end()) continue;
            current.emplace_back(num);
            backtracking(index + 1, nums, current, answer);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::vector<int> current;
        backtracking(0, nums, current, answer);
        return answer;
    }
};
