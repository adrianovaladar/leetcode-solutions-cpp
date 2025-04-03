class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> vec;
        for (const auto &interval: intervals) {
            if (vec.empty() || vec.back().at(1) <= interval.at(0))
                vec.emplace_back(interval);
            else {
                vec.back().at(1) = std::min(interval.at(1), vec.back().at(1));
            }
        }
        return intervals.size() - vec.size();
    }
};
