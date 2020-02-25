class Solution {
private:
    int mod = 1e9 + 7;
//     long long dp[502][502];
//     int cal(int p, int d) {
//         if (p < 0 || d < 0 || p > d) {
//             return 1;
//         }
//         if (dp[p][d] != -1) {
//             return dp[p][d];
//         }
        
//         dp[p][d] = 1ll * p * cal(p-1, d) % mod;
//         dp[p][d] += 1ll * (d - p) * cal(p, d-1) % mod;
            
//         return dp[p][d];
//     }
public:
    int countOrders(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        //std::memset(dp, -1, sizeof(dp));
        // dp[0][0] = 1;
        // int sum = 0;
        // for (int i = 1; i <= n; i++) {
        //     dp[i][0] = dp[i-1][0] * (n+1-i) % mod;
        //     for (int j = 1; j <= i; j++) {
        //         dp[i][j] = dp[i][j-1] * (i+1-j) % mod;
        //     }
        // }
        
        return ((2ll*n-1) * n) * countOrders(n-1) % mod;
    }
};
