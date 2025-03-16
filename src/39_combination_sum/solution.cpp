class Solution {
    void backtracking(int index, int target, int total, std::vector<int> &currentSum, std::vector<int> &candidates, std::vector<std::vector<int>> &answer) {
        if (total == target) answer.emplace_back(currentSum);
        for (int i{index}; i < candidates.size(); i++) {
            if (total + candidates.at(i) > target) return;
            currentSum.emplace_back(candidates.at(i));
            backtracking(i, target, total + candidates.at(i), currentSum, candidates, answer);
            currentSum.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        if (candidates.size() == 0) return {{}};
        std::vector<std::vector<int>> answer;
        std::vector<int> currentSum;
        backtracking(0, target, 0, currentSum, candidates, answer);
        return answer;
    }
};
