class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::pair<int,int>> sortedQueries;
        for (int i{}; const auto &q: queries) {
            sortedQueries.emplace_back(q, i);
            i++;
        }
        std::sort(sortedQueries.begin(), sortedQueries.end());
        int i {};
        int n = intervals.size();
        std::vector<int> answer(queries.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;        
        for (auto& [query, index] : sortedQueries) {
            while (i < n && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                int size = right - left + 1;
                minHeap.push({size, right});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                answer[index] = minHeap.top().first;
            }
        }
        return answer;
    }
};
