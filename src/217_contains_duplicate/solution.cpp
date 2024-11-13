class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> occurrences;
        auto it = nums.begin();
        while(it != nums.end()) {
            if (occurrences[*it] == 1)
                return true;
            occurrences[*it]++;
            it++;
        }
        return false;
    }
};
