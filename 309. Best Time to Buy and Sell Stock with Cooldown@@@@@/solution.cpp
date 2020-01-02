class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        
        int cooldown = 0;
        int sold = 0;
        int hold = INT_MIN;
        for (auto i : prices) {
            int prevSold = sold;
            sold = i + hold;
            hold = std::max(hold, cooldown - i);
            cooldown = std::max(cooldown, prevSold);
        }
        
        return std::max(sold, cooldown);
    }
};
