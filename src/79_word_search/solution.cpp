#include <vector>
#include <string>

class Solution {
    bool backtracking(int x, int y, int lines, int columns, int current, std::vector<std::vector<char>>& board, std::string &word, std::vector<std::vector<bool>>& visited) {
        if (current == word.size()) return true;
        if (x < 0 || x >= lines || y < 0 || y >= columns || visited[x][y]) return false;
        if (board[x][y] != word[current]) return false;
        visited[x][y] = true;
        if (backtracking(x + 1, y, lines, columns, current + 1, board, word, visited) ||
            backtracking(x - 1, y, lines, columns, current + 1, board, word, visited) ||
            backtracking(x, y + 1, lines, columns, current + 1, board, word, visited) ||
            backtracking(x, y - 1, lines, columns, current + 1, board, word, visited)) {
            return true; 
        }
        visited[x][y] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int columns = board[0].size();
        int lines = board.size();
        if (word.size() > lines * columns) {
            return false;
        }
        std::vector<std::vector<bool>> visited(lines, std::vector<bool>(columns, false));
        for (int i = 0; i < lines; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (backtracking(i, j, lines, columns, 0, board, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
