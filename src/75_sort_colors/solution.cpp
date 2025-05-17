class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::map<int,int> mp;
        for (const auto &num : nums) {
            mp[num]++;
        }
        nums.clear();
        for (const auto &elem : mp) {
            for(int i{}; i < elem.second; i++)
                nums.emplace_back(elem.first);
        }
    }
};
