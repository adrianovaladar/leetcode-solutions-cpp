class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numZeroes{};
        nums.erase(remove_if(nums.begin(), nums.end(), [&numZeroes] (int num) {if (num == 0) {numZeroes++; return true;} else return false;}), nums.end());
        for (int i {}; i < numZeroes; i++)
           nums.emplace_back(0);
    }
};
