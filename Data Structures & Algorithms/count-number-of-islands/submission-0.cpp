class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (visited[r][c])
            return;

        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if (newR < 0 || newR >= grid.size() || newC < 0 || newC >= grid[0].size())
                continue;
            
            if (grid[newR][newC] == '1')
                dfs(grid, visited, newR, newC);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cols = grid[0].size();
        int rows = grid.size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        int count = 0;

        // start at tile 0, 0
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {

                if (grid[r][c] == '1' && !visited[r][c]) {
                    dfs(grid, visited, r, c);
                    ++count;
                }
            }
        }

        return count;
    }
};
