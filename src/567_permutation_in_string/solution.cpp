class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        std::unordered_map<char, int> mapChars;
        int left {};
        int count {};
        for (int right {}; right < s2.size(); right++) {
            char currentChar = s2.at(right);
            if (s1.find(currentChar) == string::npos) {
                count = 0;
                left = right + 1;
                mapChars.clear();
            }
            else {
                if (mapChars[currentChar] >= std::count(s1.begin(), s1.end(), currentChar)) {
                    while (s2.at(left) != currentChar) {
                        mapChars.erase(s2.at(left));
                        left++;
                        count--;
                    }
                    left++; // move the left pointer past the first occurrence of currentChar
                }
                else {
                    count++;
                    mapChars[currentChar]++;
                    if (count == s1.size()) return true;
                }
            }
        }
        return count == s1.size();
    }
};
