class Solution {
public:
    bool checkValidString(string s) {
        int leftMin {};
        int leftMax {};
        for (const auto &c: s) {
            if (c == '(')   {
                leftMin++;
                leftMax++;
            }
            else if (c == ')') {
                leftMin--;
                leftMax--;
            }
            else {
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0; 
        }
        return leftMin == 0;
    }
};
