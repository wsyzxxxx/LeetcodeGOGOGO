class Solution {
private:
    //int dp[k+1][n];
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1 || k <= 0) {
            return 0;
        }

        int n = prices.size();
        if (k >= n/2) {
            int maxPro = 0;
            for (int i = 1; i < n; i++) {
                maxPro += (prices[i] > prices[i-1]) ? (prices[i] - prices[i-1]) : 0;
            }
            return maxPro;
        }

        //init
        int dp[k+1][n];
        for (int i = 0; i < k+1; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= k; i++) {
            int localMax = dp[i-1][0] - prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = std::max(dp[i][j-1], prices[j] + localMax);
                localMax = std::max(localMax, dp[i-1][j] - prices[j]);
            }
        }

        
        return dp[k][n-1];
    }
};