class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if (dp[r][c] != -1)
            return dp[r][c];
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        int maxNext = 0;
        for (int i = 0; i < 4; ++i) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            // OOB check
            if (newR < 0 || newR >= matrix.size() || newC < 0 || newC >= matrix[0].size())
                continue;
            
            // avoid going into "lower" neighbors
            // this also inherently avoids cycles
            if (matrix[newR][newC] <= matrix[r][c])
                continue;
            
            maxNext = max(maxNext, dfs(newR, newC, dp, matrix));
        }

        dp[r][c] = 1 + maxNext;
        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // dp grid, each entry records the longest subseq
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int maxSoFar = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(r, c, dp, matrix);
                maxSoFar = max(dp[r][c], maxSoFar);
            }
        }

        return maxSoFar;
    }
};
