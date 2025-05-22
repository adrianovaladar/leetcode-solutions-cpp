class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int answer {};
        int tmpIncrease {1};
        int tmpDecrease {1};
        int maxIncrease {1};
        int maxDecrease {1};
        for (int i {}; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i+1]) {
                tmpIncrease++;
                tmpDecrease = 1;
            }
            else if (nums[i] > nums[i+1]) {
                tmpDecrease++;
                tmpIncrease = 1;
            }
            else {
                tmpIncrease = 1;
                tmpDecrease = 1;
            }
            maxIncrease = std::max(tmpIncrease, maxIncrease);
            maxDecrease = std::max(tmpDecrease, maxDecrease);
        }
        return std::max(maxIncrease, maxDecrease);
    }
};
