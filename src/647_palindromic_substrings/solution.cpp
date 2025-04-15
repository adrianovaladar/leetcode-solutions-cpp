class Solution {
public:
    int countSubstrings(string s) {
        std::vector<std::vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int index {};
        int length {};
        int answer {};
        for (int i = s.size(); i >= 0; i--) {
            for (int j {i}; j < s.size() ; j++) {
                if (s.at(i) == s.at(j) &&
                (j - i <= 2 || dp.at(i+1).at(j-1))) {
                    dp.at(i).at(j) = true;
                    answer++;
                }
            }
        }
        return answer;
    }
};
