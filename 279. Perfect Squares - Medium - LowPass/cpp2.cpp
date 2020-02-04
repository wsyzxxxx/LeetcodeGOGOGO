class Solution {
public:
    int numSquares(int n) {
        if (n < 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        std::vector<int> dp(n+1, std::numeric_limits<int>::max());
        dp[1] = 1;
        dp[0] = 0;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = std::min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        return dp[n];
    }
};
