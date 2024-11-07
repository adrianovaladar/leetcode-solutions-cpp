class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int minimumSize = word1.size() > word2.size() ? word2.size() : word1.size();
        string biggerWord = word1.size() > word2.size() ? word1 : word2;
        string answer;
        for (int i {}; i < minimumSize ; i++) {
            answer += word1.at(i);
            answer += word2.at(i);
        }
        for (int i {minimumSize}; i < biggerWord.size(); i++) {
            answer += biggerWord.at(i);
        }
        return answer;
    }
};
