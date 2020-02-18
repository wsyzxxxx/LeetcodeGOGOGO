class Solution {
private:
    int dp[1002][1002];
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        if (n == 0 || m == 0) {
            return 0;
        }
        
        std::memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        
        return dp[n][m];
    }
};
