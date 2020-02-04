class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() < 2) {
            return 0;
        }
        
        int hold = -prices[0];
        int sold = 0;
        for (int i = 1; i < prices.size(); i++) {
            sold = std::max(sold, hold + prices[i] - fee);
            hold = std::max(hold, sold - prices[i]);
        }
        
        return sold;
    }
};
