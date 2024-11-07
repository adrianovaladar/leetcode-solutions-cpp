class Solution {
public:
    int lengthOfLastWord(string s) {
        std::reverse(s.begin(), s.end());
        std::stringstream ss;
        ss << s;
        ss >> s;
        return s.size();
    }
};
