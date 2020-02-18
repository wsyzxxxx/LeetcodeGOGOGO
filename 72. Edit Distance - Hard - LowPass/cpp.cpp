class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        if (n == 0) {
            return m;
        }
        if (m == 0) {
            return n;
        }
        
        std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1, std::numeric_limits<int>::max()));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = std::min(dp[i][j], std::min(dp[i+1][j], dp[i][j+1])) + 1;
                }
                //std::cout << i+1 << " " << j+1 << " " << dp[i+1][j+1] << std::endl;
            }
        }
        
        return dp[n][m];
    }
};
