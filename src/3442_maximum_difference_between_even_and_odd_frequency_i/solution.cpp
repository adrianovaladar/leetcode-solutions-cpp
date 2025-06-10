class Solution {
public:
    int maxDifference(string s) {
        std::vector<int> vec;
        vec.resize(26);
        for (const auto &c: s) {
            vec[c - 'a']++;
        }
        int oddFrequency {};
        int evenFrequency = INT_MAX;
        for (const auto &elem: vec) {
            if (elem % 2 == 0 && elem != 0) evenFrequency = std::min(evenFrequency, elem);
            else oddFrequency =std::max(oddFrequency, elem);
        }
        return oddFrequency - evenFrequency;
    }
};
