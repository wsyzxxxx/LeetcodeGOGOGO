class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        //init
        int n = prices.size();
        int maxProfit[n];
        for (int i = 0; i < n; i++) {
            maxProfit[i] = 0;
        }

        int minValue = prices[0];
        int maxP = 0;
        for (int i = 1; i < n; i++) {
            maxP = std::max(prices[i] - minValue, maxP);
            maxProfit[i] = maxP;
            if (prices[i] < minValue) {
                minValue = prices[i];
            }
        }

        maxP = 0;
        int maxValue = prices[n-1];
        int res = maxProfit[n-1];
        for (int i = n-2; i > 0; i--) {
            maxP = std::max(maxValue - prices[i], maxP);
            maxProfit[i] += maxP;
            res = std::max(res, maxProfit[i]);
            if (prices[i] > maxValue) {
                maxValue = prices[i];
            }
        }

        return res;
    }
};