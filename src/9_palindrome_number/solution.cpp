class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long number {x};
        long long reverse{};
        while (x != 0) {
            reverse *= 10;
            reverse += x % 10;
            x = x / 10;
        }
        return number == reverse;
    }
};
