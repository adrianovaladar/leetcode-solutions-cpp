class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        std::vector<int> answer;
        std::unordered_set<int> st;
        for (int x {}; x < digits.size(); x++) {
            for (int y {}; y < digits.size(); y++) {
                for (int z {}; z < digits.size(); z++) {
                    if (digits[x] == 0 || x == y || x == z || y == z || digits[z] % 2 != 0) continue;
                    int tmp = digits[x] * 100 + digits[y] * 10 + digits[z];
                    if (st.find(tmp) != st.end()) continue;
                    answer.emplace_back(tmp);
                    st.insert(tmp);
                }
            }
        }
        std::sort(answer.begin(), answer.end());
        return answer;
    }
};
