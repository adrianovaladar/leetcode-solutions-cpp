class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        std::sort(hand.begin(), hand.end());
        std::unordered_map<int,int> mp;
        for (const auto &num : hand) mp[num]++;
        for (const auto &num : hand) {
            if (mp[num] > 0) {
                for (int  i{num}; i < groupSize + num; i++) {
                    if (mp[i] > 0) {
                        mp[i]--;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};
