class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) {
            return 0;
        }
        
        int dp[n+1][n+1];
        int mx[n+1][n+1];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            int mxNum = arr[i];
            for (int j = i; j < n; j++) {
                mxNum = std::max(mxNum, arr[j]);
                mx[i][j] = mxNum;
            }
        }
        
        dp[n][n] = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n-j; i++) {
                int r = i + j;
                dp[i][r] = std::numeric_limits<int>::max();
                if (j == 1) {
                    dp[i][r] = arr[i] * arr[r];
                } else {
                    for (int k = i; k < r; k++) {
                        dp[i][r] = std::min(dp[i][r], dp[i][k] + dp[k+1][r] + mx[i][k] * mx[k+1][r]);
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
