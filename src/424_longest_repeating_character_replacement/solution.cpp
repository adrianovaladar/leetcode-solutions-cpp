class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> mapCharOccurrences;
        int answer {};
        int maxFrequency {};
        int left {};
        for (int right {}; right < s.size(); right++) {
            int count {};
            mapCharOccurrences[s.at(right)]++;
            maxFrequency = std::max(maxFrequency, mapCharOccurrences[s.at(right)]);
            while (right - left +  1 - maxFrequency > k) {
                mapCharOccurrences[s.at(left)]--;
                left++;
            }
            answer = std::max(answer, right - left +  1);
        
        }
        return answer;
    }
};
