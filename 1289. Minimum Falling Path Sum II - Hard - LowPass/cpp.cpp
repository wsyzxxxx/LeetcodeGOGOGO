class Solution {
    int dp[202][2];
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        if (n == 0) {
            return 0;
        }
        
        std::memset(dp, 0, sizeof(dp));
        
        int currLevel = 0;
        int lastLevel = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minPath = std::numeric_limits<int>::max();
                for (int k = 0; k < m; k++) {
                    if (k == j) {
                        continue;
                    }
                    minPath = std::min(minPath, dp[k][lastLevel]);
                }
                dp[j][currLevel] = minPath + arr[i][j];
            }
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
