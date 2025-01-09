class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        std::sort(nums.begin(), nums.end());
        int answer {1};
        int current {1};
        for (int i{}; i < nums.size() - 1; i++) {
            if (nums.at(i) == nums.at(i+1)) continue;
            if (nums.at(i) == nums.at(i+1)-1) { 
                current++;
                if (current > answer) answer = current;
            }
            else current = 1;
        }
        return answer;
    }
};
