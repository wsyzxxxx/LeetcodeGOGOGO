class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        if (n == 0) {
            return 0;
        }
        
        std::vector<int> dp(amount+1, std::numeric_limits<int>::max());
        dp[0] = 0;
        
        for (int i = 0; i < amount; i++) {
            if (dp[i] == std::numeric_limits<int>::max()) {
                continue;
            }
            
            for (int j = 0; j < n; j++) {
                if ((long)i + coins[j] <= amount) {
                    dp[i+coins[j]] = std::min(dp[i] + 1, dp[i+coins[j]]);
                }
            }
        }
        
        return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
    }
};
