class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> answer;
        std::multimap<std::array<int,26>,std::string> mmp;
        std::set<std::array<int, 26>> keys;
        for(const auto &word: strs) {
            std::array<int, 26> count;
            count.fill(0);
            for (char c : word) {
                count[c - 'a']++;
            }
            keys.insert(count);
            mmp.insert(std::make_pair(count, word));
        }
        for (const auto &key : keys) {
            auto range = mmp.equal_range(key);
            std::vector<std::string> values;
            for (auto it = range.first; it != range.second; it++) {
                values.emplace_back(it->second);
            }
            answer.emplace_back(values);
        }
        return answer;
    }
};
