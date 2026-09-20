class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size();
        int cols = text2.size();
        // make it size (rows + 1, cols + 1) to avoid boundary checks
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[rows][cols];
    }
};
