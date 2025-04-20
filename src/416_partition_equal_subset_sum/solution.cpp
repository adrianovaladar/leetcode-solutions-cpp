class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        std::unordered_set<int> st;
        st.insert(nums.back());
        st.insert(0);
        for (int i = nums.size() - 2; i>=0; i--) {
            for (auto &value: st) {
                st.insert(value);
                st.insert(value +nums.at(i));
                if (value+nums.at(i) == sum / 2) return true;
            }
        }
        return false;
    }
};
