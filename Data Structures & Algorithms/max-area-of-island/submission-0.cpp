class Solution {
public:
    int dfsIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        int islandSize = 1;
        visited[r][c] = true;

        // loop through all neighbors
        for (int i = 0; i < 4; ++i) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            
            // out of bounds check
            if (newR < 0 || newR >= grid.size() || newC < 0 || newC >= grid[0].size())
                continue;
            
            // skip if visited
            if (visited[newR][newC])
                continue;

            if (grid[newR][newC] == 1) {
                islandSize += dfsIsland(grid, visited, newR, newC);
            }
        }

        return islandSize;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSoFar = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // core loop, iterate over all tiles
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0 || visited[r][c])
                    continue;
                
                // it must be an island, so find its area
                maxSoFar = std::max(maxSoFar, dfsIsland(grid, visited, r, c));
            }
        }
        
        // ret max area of island in grid
        return maxSoFar;
    }
};
