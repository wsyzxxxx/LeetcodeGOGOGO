typedef long long LL;
LL dp[51][101][51];

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numOfArrays(int n, int m, int k) {
        if (k > m) {
            return 0;
        } else if (k == m) {
            return 1;
        }
        
        std::memset(dp, 0, sizeof(dp));
        
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int a = 1; a <= std::min(k, i); a++) {
                    for (int l = 0; l <= m; l++) {
                        if (j > l)
                            dp[i][j][a] = (dp[i-1][l][a-1] + dp[i][j][a]) % mod;
                        else
                            dp[i][l][a] = (dp[i-1][l][a]   + dp[i][l][a]) % mod;
                    }
                }
            }
        }
        
        long long sum = 0;
        for (int i = 1; i <= m; i++) {
            //std::cout << i << " " << dp[n][i][k] << std::endl;
            sum = (sum + dp[n][i][k]) % mod;
        }
        
        return sum;
    }
};
