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
            int mi = std::numeric_limits<int>::max() - 200;
            for (int j = 0; j < m; j++) {
                dp[j][currLevel] = mi + arr[i][j];
                mi = std::min(mi, dp[j][lastLevel]);
            }
            mi = std::numeric_limits<int>::max() - 200;
            for (int j = m-1; j >= 0; j--) {
                dp[j][currLevel] = std::min(dp[j][currLevel], mi + arr[i][j]);
                mi = std::min(mi, dp[j][lastLevel]);
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
