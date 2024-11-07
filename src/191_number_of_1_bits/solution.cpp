class Solution {
public:
    int hammingWeight(int n) {
    bitset<std::numeric_limits<uint32_t>::digits> bitset(n);
    return bitset.count();
    }
};
