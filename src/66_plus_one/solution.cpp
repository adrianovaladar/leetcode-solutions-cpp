class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        digits.at(digits.size() - 1) += 1;
        while(index >= 0) {
            if (digits.at(index) <= 9)
                break;
            digits.at(index) = 0;
            if (index == 0) {
                digits.insert(digits.begin(), 1);
            }
            else
                digits.at(index-1)++;
            index--;
        }
        return digits;
    }
};
