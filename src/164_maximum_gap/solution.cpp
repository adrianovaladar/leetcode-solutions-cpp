class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int max {};
        sort(nums.begin(), nums.end());
        for(int i{}; i < nums.size() - 1; i++) {
            int ans = nums.at(i+1) - nums.at(i);
            if (ans > max)
                max = ans;
        }
        return max;
    }
};
