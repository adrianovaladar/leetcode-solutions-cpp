class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        if (n == INT_MAX) return x == 1 ? 1 : x == -1 ? -1 : 0;
        if (n == INT_MIN) return x == 1 || x == -1 ? 1 : 0;
        double answer {1};
        for (int i{}; i < abs(n); i++) {
            answer *=x;
        }
        if (n < 0) {
            answer = 1 / answer;
        }
        return answer;
    }
};
