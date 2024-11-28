class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        std::unordered_map<char,char> mp;
        size_t size = s.size();
        for (int i {}; i < size; i++) {
            if (count_if(mp.begin(), mp.end(), [s = s.at(i), t = t.at(i)] (auto pair) {return s != pair.first && t == pair.second;})) return false;   
            mp[s.at(i)] = t.at(i);
        }
        for(auto elem: t) {
            if (std::find_if(mp.begin(), mp.end(), [elem](std::pair<char,char>pair){return pair.second == elem;}) == mp.end()) return false;
        }
        return true;
    }
};
