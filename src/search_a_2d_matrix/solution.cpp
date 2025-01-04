class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto begin = std::begin(matrix);
        auto end = std::end(matrix);
        auto it = std::find_if(begin, end, [&](auto row) {
        auto rowBegin = std::begin(row);
        auto rowEnd = std::end(row);
        return std::find(rowBegin, rowEnd, target) != rowEnd;
    });
    return it != end;
    }
};
