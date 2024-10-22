class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i{} ; i < nums.size(); i++) {
            if (i < nums.size() - 1 && nums.at(i) == nums.at(i+1)) {
                nums.at(i) *= 2;
                nums.at(i+1) = 0;
            }
        }
        int numZeroes{};
        nums.erase(remove_if(nums.begin(), nums.end(), [&numZeroes] (int num) {if (num == 0) {numZeroes++; return true;} else return false;}), nums.end());
        for (int i {}; i < numZeroes; i++)
            nums.push_back(0);
        return nums;
    }
};
