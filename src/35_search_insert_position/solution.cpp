class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i {}; i < nums.size(); i++) {
            if (nums.at(i) >= target)
                return i;
        }
        return nums.size();
    }
};
