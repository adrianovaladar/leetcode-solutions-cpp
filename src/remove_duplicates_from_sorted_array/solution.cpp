class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::set<int> set;
        auto element = nums.begin();
        while (element != nums.end()) {
            set.insert(*element);
            element++;
        }
        nums.clear();
        nums.resize(set.size());
        std::copy(set.begin(), set.end(), nums.begin());
        return nums.size();
    }
};
