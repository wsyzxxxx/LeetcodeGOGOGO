unsigned long long dp[1005];

class Solution {
public:
    int numDistinct(string s, string t) {
        std::memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = std::min(i, (int)t.size()-1); j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[j+1] = dp[j+1] + dp[j];
                }
            }
        }
        
        return dp[t.size()];
    }
};