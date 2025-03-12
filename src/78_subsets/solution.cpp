class Solution {
    void backtrack(int index, std::vector<int> &current, std::vector<int> &nums, std::vector<std::vector<int>> &answer) {
        answer.emplace_back(current);
        for (int i {index}; i < nums.size(); i++) {
            current.emplace_back(nums.at(i));
            backtrack(i + 1, current, nums, answer);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return {{}};
        std::vector<std::vector<int>> answer;
        std::vector<int> current;
        backtrack(0, current, nums, answer);
        return answer;
    }
};
