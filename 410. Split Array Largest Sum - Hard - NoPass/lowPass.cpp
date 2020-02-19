class Solution {
private:
    int dp[1002][52]; // dp[i][j] = min Sum with i elements into m sub arrays
    long subSum[1002];
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = std::numeric_limits<int>::max();
            }
        }
        //std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1, INT_MAX));
        //std::vector<long long> subSum(n+1, 0);
        subSum[0] = 0;
        for (int i = 0; i < n; i++) {
            subSum[i+1] = nums[i] + subSum[i];
        }
        
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= std::min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = std::min(dp[i][j], std::max(dp[k][j-1], (int)(subSum[i] - subSum[k])));
                }
            }
        }
        
        return dp[n][m];
    }
};
