class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> answer;
        for (int i {}; i <= n; i++) {
            std::bitset<std::numeric_limits<unsigned int>::digits> bs(i);
            answer.emplace_back(bs.count());
        }
        return answer;
    }
};
