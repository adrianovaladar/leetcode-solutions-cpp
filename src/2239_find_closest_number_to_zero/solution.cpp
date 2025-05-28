class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer{nums.at(0)};
        for(const auto &num: nums) {
            if (abs(num) <= abs(answer))
                answer = num;
        }
        return answer;
    }
};
