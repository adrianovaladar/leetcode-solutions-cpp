class Solution {
    void dfs(vector<vector<char>>& board, int line, int column) {
        if (board.at(line).at(column) != 'O') return;
        int lines = board.size();
        int columns = board.at(0).size();        
        board.at(line).at(column) = 'T';
        if (line - 1 >= 0) dfs(board, line - 1, column);
        if (line + 1 < lines) dfs(board, line + 1, column);
        if (column - 1 >= 0) dfs(board, line, column - 1);
        if (column + 1 < columns) dfs(board, line, column + 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        int lines = board.size();
        int columns = board.at(0).size();
        for (int i {}; i < lines; i++) {
            for (int j {}; j < columns; j++) {
                if ((j == 0 || i == 0 || i == lines - 1 || j == columns - 1) && board.at(i).at(j) == 'O') dfs(board, i, j);
            }
        }
        for (int i {}; i < lines; i++) {
            for (int j {}; j < columns; j++) {
                if (board.at(i).at(j) == 'O') board.at(i).at(j) = 'X';
            }
        }
        for (int i {}; i < lines; i++) {
            for (int j {}; j < columns; j++) {
                if (board.at(i).at(j) == 'T') board.at(i).at(j) = 'O';
            }
        }        
    }
};
