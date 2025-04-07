class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        std::vector<std::vector<int>> candidates;
        std::vector<int> count(3);
        for (const auto &triplet: triplets) {
            if (triplet.at(0) > target.at(0) 
                || triplet.at(1) > target.at(1)
                || triplet.at(2) > target.at(2)) continue;
            for (int i{}; i < triplet.size(); i++) {
                if (triplet.at(i) == target.at(i)) count.at(i)++;
            }
            if (std::find(count.begin(), count.end(), 0) == count.end()) return true;
        }
        return false;
    }
};
