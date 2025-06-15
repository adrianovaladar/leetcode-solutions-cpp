class Solution {
public:
    int maxDiff(int num) {
        std::string a = std::to_string(num);
        std::string b = std::to_string(num);
        int positionA = a.find_first_not_of('9');
        if (positionA != string::npos) {
            char valueA = a[positionA];
            replace(a.begin(), a.end(), valueA, '9');
        }
        int positionB = b.find_first_not_of("01");
        if (positionB != string::npos) {
            char valueB = b[positionB];
            if (positionB == 0) replace(b.begin(), b.end(), valueB, '1');
            else replace(b.begin(), b.end(), valueB, '0');
        }
        return stoi(a) - stoi(b);
    }
};
