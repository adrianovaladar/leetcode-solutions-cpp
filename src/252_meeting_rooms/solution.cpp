class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;
        std::sort(intervals.begin(), intervals.end());
        for (int i{}; i < intervals.size() - 1; i++) {
            if (intervals.at(i).at(1) > intervals.at(i+1).at(0)) return false;
        }
        return true;
    }
};
