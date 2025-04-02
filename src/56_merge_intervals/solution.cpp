class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> answer;
        for (const auto &interval: intervals) {
            if (answer.empty() || answer.back().at(1) < interval.at(0))
                answer.emplace_back(interval);
            else
                answer.back().at(1) = std::max(answer.back().at(1), interval.at(1));
        }
        return answer;
    }
};
