unsigned long long dp[1005][1005];

class Solution {
public:
    int numDistinct(string s, string t) {
        std::memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < s.size(); i++) {
            dp[i][0] = 1;
            for (int j = 0; j <= std::min(i, (int)t.size()-1); j++) {
                if (s[i] == t[j]) {
                    dp[i+1][j+1] = dp[i][j+1] + dp[i][j];
                } else {
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }
        
        return dp[s.size()][t.size()];
    }
};