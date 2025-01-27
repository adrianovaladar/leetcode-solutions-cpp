class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int,int> mp;
        for (const auto &elem: arr) {
            mp[elem]++;
        }
        std::unordered_set<int> st;
        for (const auto &elem: mp) {
            if (st.find(elem.second) != st.end()) return false;
            st.insert(elem.second);
        }
        return true;
    }
};
