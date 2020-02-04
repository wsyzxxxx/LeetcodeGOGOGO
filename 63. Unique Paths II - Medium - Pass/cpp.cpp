class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        std::vector<long> dp(m, 0);
        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i = 1; i < m; i++) {
            dp[i] = (obstacleGrid[0][i] == 0) ? dp[i-1] : 0;
        }
        
        for (int i = 1; i < n; i++) {
            dp[0] = (obstacleGrid[i][0] == 0) ? dp[0] : 0;
            for (int j = 1; j < m; j++) {
                dp[j] = (obstacleGrid[i][j] == 0) ? (dp[j-1] + dp[j]) : 0;
            }
        }
        
        return dp[m-1];
    }
};
