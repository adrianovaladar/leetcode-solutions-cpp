class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, unordered_set<char>> valuesRows;    
        std::unordered_map<int, unordered_set<char>> valuesColumns;    
        std::map<pair<int, int>, unordered_set<char>> valuesSquares;
        for(int rows{}; rows < board.size(); rows++) {
            for(int columns{}; columns < board.size(); columns++) {
                if (board.at(rows).at(columns) == '.') continue;
                std::pair<int, int> squareKey = {rows / 3, columns / 3};
                if(valuesColumns[columns].count(board.at(rows).at(columns)) 
                || valuesRows[rows].count(board.at(rows).at(columns))
                || valuesSquares[squareKey].count(board.at(rows).at(columns)))
                    return false;                
                valuesColumns[columns].insert(board.at(rows).at(columns));
                valuesRows[rows].insert(board.at(rows).at(columns));
                valuesSquares[squareKey].insert(board[rows][columns]);
            }    
        }
        return true;
    }
};
