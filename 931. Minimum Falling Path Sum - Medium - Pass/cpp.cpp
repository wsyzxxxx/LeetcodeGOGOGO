class Solution {
    int dp[102][2];
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        if (n == 0) {
            return 0;
        }
        if (m == 1) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                sum += A[i][0];
            }
            return sum;
        }
        
        std::memset(dp, 0, sizeof(dp));
        
        int currLevel = 0;
        int lastLevel = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    dp[j][currLevel] = std::min(dp[j][lastLevel], dp[j+1][lastLevel]) + A[i][j];
                } else if (j == m-1) {
                    dp[j][currLevel] = std::min(dp[j][lastLevel], dp[j-1][lastLevel]) + A[i][j];
                } else {
                    dp[j][currLevel] = std::min(dp[j][lastLevel], std::min(dp[j+1][lastLevel], dp[j-1][lastLevel])) + A[i][j];
                }
                //std::cout << dp[j][currLevel] << " ";
            }
            std::cout << std::endl;
            currLevel = 1 - currLevel;
            lastLevel = 1 - lastLevel;
        }
        
        int minSum = std::numeric_limits<int>::max();
        for (int i = 0; i < m; i++) {
            minSum = std::min(minSum, dp[i][lastLevel]);
        }
        
        return minSum;
    }
};
