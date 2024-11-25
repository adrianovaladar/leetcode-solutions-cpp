class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char,int> charactersOccurrences;
        for (const auto &character : magazine) {
            charactersOccurrences[character]++;
        }
        for (const auto &character : ransomNote) {
            charactersOccurrences[character]--;
        }
        for (const auto& pair : charactersOccurrences) {
            if (pair.second < 0)
                return false;
        }
        return true;
    }
};
