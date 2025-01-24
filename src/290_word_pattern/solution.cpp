class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, std::string> charToString;
        std::unordered_map<std::string, char> stringToChar;
        std::stringstream ss {s};
        std::string word;
        for (const auto &character : pattern) {
            ss >> word;
            if (charToString.count(character) && charToString[character] != word) {
                return false;
            }
            if (stringToChar.count(word) && stringToChar[word] != character) {
                return false;
            }
            charToString[character] = word;
            stringToChar[word] = character;            
        }
        return !(ss >> word);
    }
};
