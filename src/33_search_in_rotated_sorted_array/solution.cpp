class Solution {
public:
    int search(vector<int>& nums, int target) {
        int value = std::distance(nums.begin(), find_if(nums.begin(), nums.end(), [target](int num) {return target == num;}));
        return value < nums.size() ? value : -1;
    }
};
