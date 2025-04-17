class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.at(0);
        std::vector<int> dp(nums.size());;
        dp.at(0) = nums.at(0);
        dp.at(1) = std::max(nums.at(0), nums.at(1));
        for (int i {2}; i < nums.size(); i++) {
            dp.at(i) = std::max(dp.at(i-1), nums.at(i) + dp.at(i-2));
        }
        return dp.back();
    }    }
};
