class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return std::string();
        std::unordered_map<char,int> tOccurrences;
        for (const auto &c: t) {
            tOccurrences[c]++;
        }        
        int left {};
        std::string answer;
        std::unordered_map<char,int> charactersOccurrences;
        std::string currentAnswer;
        int numberCharacters{};        
        for(int right {}; right < s.size(); right++) {
            charactersOccurrences[s.at(right)]++;
            currentAnswer+=s.at(right);
            if (charactersOccurrences[s.at(right)] <= tOccurrences[s.at(right)] && tOccurrences.count(s.at(right))) {
                numberCharacters++;
            }                            
            while (numberCharacters == t.size() && left <= right) {
                if (currentAnswer.size() < answer.size() || answer.empty())
                    answer = currentAnswer;
                currentAnswer.erase(0, 1);
                if (charactersOccurrences[s.at(left)] == tOccurrences[s.at(left)]) {
                    numberCharacters--;
                }
                charactersOccurrences[s.at(left)]--;
                left++;
            }          
        }
        return answer;
    }
};
