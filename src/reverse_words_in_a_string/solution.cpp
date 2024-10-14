class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss {s};
        std::string ans;
        std::string word;
        while (ss >> word) {
            if (!ans.empty()) {
                ans = " " + ans;
            }
            ans = word + ans;
        }
        return ans;
    }
};
