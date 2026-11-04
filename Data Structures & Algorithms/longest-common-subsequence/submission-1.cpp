class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // 2D grid, (m + 1, n + 1)
        // where dp[i][j] = how many chars matched
        // first i chars from text1, first j chars from text2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j) {
                int s1 = INT_MIN;
                int s2 = max(dp[i][j-1], dp[i-1][j]);

                if (text1[i - 1] == text2[j - 1])
                    s1 = dp[i-1][j-1] + 1;
                
                dp[i][j] = max(s1, s2);
            }
        
        return dp[m][n];
    }
};
