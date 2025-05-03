class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        std::vector<int> result(num1.length() + num2.length(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                result.at(i + j + 1) += (num1.at(i) - '0') * (num2.at(j) - '0');
                result.at(i + j) += result.at(i + j + 1) / 10;
                result.at(i + j + 1) %= 10;
            }
        }
        std::stringstream answer;
        int startIndex = result.at(0) == 0 ? 1 : 0;
        for (int i {startIndex}; i < result.size(); i++) answer << std::to_string(result.at(i));
        return answer.str();
    }
};
