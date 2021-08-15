int dp[2][25];

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        std::memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < costs[0].size(); i++) {
            dp[0][i] = costs[0][i];
        }
        
        int currLevel = 1;
        for (int i = 1; i < costs.size(); i++) {
            std::priority_queue<std::pair<int, int>,
                                std::vector<std::pair<int, int>>,
                                std::less<std::pair<int, int>>> pq;
            
            for (int j = 0; j < costs[i].size(); j++) {
                pq.push(std::make_pair(dp[1-currLevel][j], j));
                if (pq.size() > 2) {
                    pq.pop();
                }
            }
            
            int backUpCost = pq.top().first;
            pq.pop();
            int cost = pq.top().first;
            int color = pq.top().second;
            //std::cout << cost << " " << color << std::endl;
            for (int j = 0; j < costs[i].size(); j++) {
                if (j == color) {
                    dp[currLevel][j] = backUpCost + costs[i][j];
                } else {
                    dp[currLevel][j] = cost + costs[i][j];
                }
            }
            
            currLevel = 1 - currLevel;
        }
        
        int totalCost = dp[1-currLevel][0];
        for (int i = 1; i < costs[0].size(); i++) {
            totalCost = std::min(totalCost, dp[1-currLevel][i]);
            //std::cout << dp[1-currLevel][i] << " ";
        }
        //std::cout << std::endl;
        
        return totalCost;
    }
};