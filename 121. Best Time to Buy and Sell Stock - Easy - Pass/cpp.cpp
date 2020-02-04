class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int currMin = INT_MAX;
        int maxDiff = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < currMin) {
                currMin = prices[i];
            }
            
            if (prices[i] - currMin > maxDiff) {
                maxDiff = prices[i] - currMin;
            }
        }
        if (prices.back() - currMin > maxDiff) {
                maxDiff = prices.back() - currMin;
        }
        
        return maxDiff;
    }
};
