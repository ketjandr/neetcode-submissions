class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rottenCount = 0;
        int orangeCount = 0;

        queue<pair<int, int>> q; // queue for BFS later

        // populate the counts first
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    ++orangeCount;
                    if (grid[i][j] == 2) {
                        ++rottenCount;
                        q.push({i, j});
                    }  
                }
            }
        }

        int timeElapsed = 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int batchSize = rottenCount;

        // bfs over oranges
        while (!q.empty()) {
            // next batch/round has started
            if (batchSize == 0) {
                batchSize = q.size();
                timeElapsed++;
            }
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int newR = r + dr[i];
                int newC = c + dc[i];

                // OOB check
                if (newR < 0 || newR >= rows || newC < 0 || newC >= cols)
                    continue;
                
                if (grid[newR][newC] == 1 && !visited[newR][newC]) {
                    q.push({newR, newC});
                    visited[newR][newC] = true;
                    rottenCount++;
                }
            }

            batchSize--;
        }
        
        if (rottenCount == orangeCount)
            return timeElapsed;
        
        return -1;
    }
};
