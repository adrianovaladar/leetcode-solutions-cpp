class Solution {
    std::unordered_map<char, std::string> keypad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtracking(int index, std::string &currentAnswer, std::vector<std::string> &answer, const std::string &digits) {
        if (currentAnswer.size() == digits.size()) {answer.emplace_back(currentAnswer); return;}
        std::string letters = keypad[digits.at(index)];
        for (const auto & letter: letters) {
            currentAnswer += letter;
            backtracking(index + 1, currentAnswer, answer, digits);
            currentAnswer.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        std::string currentAnswer;
        std::vector<std::string> answer;
        backtracking(0, currentAnswer, answer, digits);
        return answer;
    }
};
