class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start {};
        int end = intervals.size() - 1;
        int target {newInterval.at(0)};
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target < intervals.at(mid).at(0)) end = mid - 1;
            else start = mid + 1;
        }
        intervals.insert(intervals.begin() + start, newInterval);
        std::vector<std::vector<int>> answer;
        for (const auto &interval: intervals) {
            if (answer.empty() || answer.back().at(1) < interval.at(0)) {
                answer.emplace_back(interval);
            }
            else
                answer.back().at(1) = std::max(interval.at(1), answer.back().at(1));
        }
        return answer;
    }
};
