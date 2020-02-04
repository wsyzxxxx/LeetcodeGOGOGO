class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        
        if (k >= prices.size() / 2) {
            int profits = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i-1]) {
                    profits += prices[i] - prices[i-1];
                }
            }
            
            return profits;
        }
        
        std::vector<std::vector<int> > profits(k+1, std::vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; i++) {
            int hold = prices[0];
            for (int j = 1; j < prices.size(); j++) {
                profits[i][j] = std::max(profits[i][j-1], prices[j] - hold);
                hold = std::min(hold, prices[j] - profits[i-1][j-1]);
            }
        }
        
        return profits[k][prices.size()-1];
    }
};
