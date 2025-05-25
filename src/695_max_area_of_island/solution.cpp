class Solution {
    void dfs(std::vector<std::vector<int>>& grid, int row, int column, int &size) {
        int rows = grid.size();
        int columns = grid.at(0).size();
        grid.at(row).at(column) = 0;
        size++;
        if (row + 1 < rows && grid.at(row + 1).at(column) == 1) dfs(grid, row + 1, column, size);
        if (row - 1 >= 0 && grid.at(row - 1).at(column) == 1) dfs(grid, row - 1, column, size);
        if (column + 1 < columns && grid.at(row).at(column + 1) == 1) dfs(grid, row, column + 1, size);
        if (column - 1 >= 0 && grid.at(row).at(column - 1) == 1) dfs(grid, row, column - 1, size);
    }    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (!rows) return 0;
        int columns = grid.at(0).size();
        int numberIslands {};
        std::vector<int> sizeIslands;
        for (int i {}; i < rows; i++) {
            for (int j {}; j < columns; j++) {
                if (grid.at(i).at(j) == 1) {
                    int size{};
                    numberIslands++;
                    dfs(grid, i, j, size);
                    sizeIslands.emplace_back(size);
                }
            }
        }
        return sizeIslands.empty() ? 0 : *max_element(sizeIslands.begin(), sizeIslands.end());
    }
};
