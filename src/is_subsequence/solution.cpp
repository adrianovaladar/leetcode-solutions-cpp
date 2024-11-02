class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto itS = s.begin();
        if (s == t) return true;
        for (const auto &character: t) {
            if (*itS == character)
                itS++;
            if (itS == s.end())
                return true;
        }
        return false;
    }
};
