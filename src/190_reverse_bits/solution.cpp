class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::string binaryString = std::bitset<32>(n).to_string();
        std::reverse(binaryString.begin(), binaryString.end());
        return std::bitset<32>(binaryString).to_ulong();
    }
};
