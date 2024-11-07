class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [] (char c) {return !isalnum(c);}), s.end());
        std::transform(s.begin(), s.end(), s.begin(),
               [](char c){ return std::tolower(c); });
        if (s.size() == 0) return true;
        string s1 = s.substr(0, (s.size() / 2));
        string s2 = s.substr((s.size() +1) / 2, s.size());
        std::reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};
