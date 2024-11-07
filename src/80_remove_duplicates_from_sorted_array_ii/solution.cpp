class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::map <int,int> map;
        auto element = nums.begin();
        while (element != nums.end()) {
            map[*element]++;
            if (map[*element] > 2)
                nums.erase(element);
            else
                element++;
        }
        return nums.size();
    }
};
