class Solution {
public:
    int reverse(int x) {
        bool negativeNumber = false;
        if (x < 0) {
            negativeNumber = true;
            x = abs(x);
        }
        std::string s {to_string(x)};
        std::reverse(s.begin(), s.end());
        int result {};
        std::string maxInt {to_string(INT_MAX)};
        if (s.length() < maxInt.length() || s <= maxInt)
           result = stoi(s);
        if (negativeNumber)
            result = -result;
        return result;
    }
};
