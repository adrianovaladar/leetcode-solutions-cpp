class Solution {
    void dfs(std::vector<std::vector<char>>& grid, int row, int column) {
        int rows = grid.size();
        int columns = grid.at(0).size();
        grid.at(row).at(column) = '0';
        if (row + 1 < rows && grid.at(row + 1).at(column) == '1') dfs(grid, row + 1, column);
        if (row - 1 >= 0 && grid.at(row - 1).at(column) == '1') dfs(grid, row - 1, column);
        if (column + 1 < columns && grid.at(row).at(column + 1) == '1') dfs(grid, row, column + 1);
        if (column - 1 >= 0 && grid.at(row).at(column - 1) == '1') dfs(grid, row, column - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (!rows) return 0;
        int columns = grid.at(0).size();
        int numberIslands {};
        for (int i {}; i < rows; i++) {
            for (int j {}; j < columns; j++) {
                if (grid.at(i).at(j) == '1') {
                    numberIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numberIslands;
    }
};
