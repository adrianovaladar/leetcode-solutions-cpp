class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> vec(n);
        vec.at(vec.size()-1) = 1;
        vec.at(vec.size()-2) = 2;
        for (int i = vec.size() - 3; i >= 0; i--) {
            vec.at(i) = vec.at(i+1) + vec.at(i+2);
        }
        return vec.at(0);
    }
};
