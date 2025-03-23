class Solution {
    std::set<int> column; 
    std::set<int> negativeDiagonal;
    std::set<int> positiveDiagonal;
    void backtracking(int row, int n, std::vector<std::string> &currentAnswer, std::vector<std::vector<std::string>> &answer) {
        if (row == n) answer.emplace_back(currentAnswer);
        for (int i {}; i < n; i++) {
            int currentPositiveDiagonal = row + i;
            int currentNegativeDiagonal = row - i;
            if (column.find(i) != column.end() || negativeDiagonal.find(currentNegativeDiagonal) != negativeDiagonal.end() || positiveDiagonal.find(currentPositiveDiagonal) != positiveDiagonal.end()) continue;
            column.insert(i);
            negativeDiagonal.insert(currentNegativeDiagonal);
            positiveDiagonal.insert(currentPositiveDiagonal);
            currentAnswer[row][i] = 'Q';
            backtracking(row + 1, n, currentAnswer, answer);
            column.erase(i);
            negativeDiagonal.erase(currentNegativeDiagonal);
            positiveDiagonal.erase(currentPositiveDiagonal);
            currentAnswer[row][i] = '.';
        }
    } 

public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::string> currentAnswer(n, std::string(n, '.'));
        std::vector<std::vector<std::string>> answer;
        backtracking(0, n, currentAnswer, answer);
        return answer;
    }
};
