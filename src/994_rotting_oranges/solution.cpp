class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid.at(0).size();
        int time {};
        int freshOranges {};
        std::queue<std::pair<int,int>> rottenOranges;
        for (int i {}; i < rows; i++) {
            for (int j {}; j < columns; j++) {
                if (grid.at(i).at(j) == 2) {
                    rottenOranges.push({i, j});
                }
                else if (grid.at(i).at(j) == 1) {
                    freshOranges++;                    
                }
            }
        }
        std::vector<std::pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};        
        while (!rottenOranges.empty() && freshOranges > 0) {
            int size = rottenOranges.size();
            for (int i {}; i < size; i++) {
                std::pair<int,int> currentPosition = rottenOranges.front();
                rottenOranges.pop();
                for (const auto &direction : directions) {
                    int newRow = currentPosition.first + direction.first;
                    int newCol = currentPosition.second + direction.second;
                    if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= columns 
                        || grid.at(newRow).at(newCol) != 1) {
                        continue;
                    }
                    grid[newRow][newCol] = 2;
                    rottenOranges.push({newRow, newCol});
                    freshOranges--;
                }
            }
            time++;
        }
        return freshOranges == 0 ? time : -1;
    }
};
