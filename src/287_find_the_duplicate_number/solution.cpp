class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> setNumbers;
        for (const auto &num: nums) {
            if (setNumbers.find(num) != setNumbers.end()) return num;
            setNumbers.insert(num);
        }
        return -1;
    }
};
