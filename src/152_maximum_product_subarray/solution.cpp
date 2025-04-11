class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums.at(0);
        int prefix{};
        int suffix {};
        int answer{};
        for (int i {}; i < nums.size(); i++) {
            prefix = nums.at(i) * (prefix == 0 ? 1 : prefix);
            suffix = nums.at(nums.size() - 1 - i) * (suffix == 0 ? 1 : suffix);
            answer = std::max(answer, std::max(prefix, suffix));
        }
        return answer;
    }
};
