class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum {};
        for (int i {}; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums.at(i)) {
                return i;
            }
            leftSum += nums.at(i);
        }
        return -1;
    }
};
