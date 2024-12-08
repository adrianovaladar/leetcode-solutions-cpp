class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> answer;
        std::sort(nums.begin(), nums.end());
        int current {};
        std::unordered_set<int> usedValues;
        for(int i {}; i < nums.size(); i++) {
            if (nums.at(i) > 0) continue;
            if (i>0 && nums.at(i) == nums.at(i - 1)) continue;
            int left = i + 1;
            int right = nums.size() -1;
            while (left < right) {
                int value = nums.at(i) + nums.at(left) + nums.at(right);
                if (nums.at(i) + nums.at(left) + nums.at(right) < 0)
                    left++;
                else if (value > 0)
                    right--;
                else {
                    answer.insert({nums.at(i), nums.at(left), nums.at(right)});
                    left++;
                    right--;
                }
            }
        }
        return vector<vector<int>>(answer.begin(), answer.end());
    }
};
