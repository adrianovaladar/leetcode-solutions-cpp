class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::set<int> lines;
        std::set<int> columns;
        for (int i {}; i < matrix.size(); i++) {
            for (int j {}; j < matrix.at(0).size(); j++) {
                if (matrix.at(i).at(j) == 0) {
                    lines.insert(i);
                    columns.insert(j);
                }
            } 
        }
        for (int i {}; i < matrix.size(); i++) {
            for (int j {}; j < matrix.at(0).size(); j++) {
                if (lines.find(i) != lines.end() || columns.find(j) != columns.end()) matrix.at(i).at(j) = 0;
            }
        }        
    }
};
