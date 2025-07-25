class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::vector<std::vector<int>> answer;
        std::sort(nums.begin(), nums.end());
        for (int i {}; i < nums.size(); i+=3) {
            if (nums[i+2] <= nums[i] + k) answer.push_back({nums[i], nums[i+1], nums[i+2]});
            else return {};
        }
        return answer;
    }
};
