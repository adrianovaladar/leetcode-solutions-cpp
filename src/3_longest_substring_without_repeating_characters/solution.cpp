class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maximum {};
        int currentValue {};
        std::set<char> setChars;
        auto left = s.begin();
        for (auto right = s.begin(); right != s.end(); right++) {
            while(setChars.count(*right) == 1) {
                setChars.erase(*left);
                left++;
            }
            setChars.insert(*right);
            if (setChars.size() > maximum)
                maximum = setChars.size();
        }

        return maximum;
    }
};
