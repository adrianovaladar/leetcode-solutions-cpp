class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum {};
        int answer {nums.at(0)};
        for (const auto &num: nums) {
            if (maximum < 0)
                maximum = 0;            
            maximum +=num;
            answer = max(maximum,answer);
        }
        return answer;
    }
};
