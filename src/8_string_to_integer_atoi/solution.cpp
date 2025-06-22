class Solution {
public:
    int myAtoi(string s) {
        int result {};
        std::stringstream ss(s);
        ss >> result;
        return result;
    }
};
