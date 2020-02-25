int cost[11][11];

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        std::queue<std::pair<int, int> > q;
        std::memset(cost, 0, sizeof(cost));
        
        int n = grid.size();
        int m = grid[0].size();
        
        int freshCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    freshCount++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        //std::cout << freshCount << std::endl;
        int maxCost = 0;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if (i > 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                cost[i-1][j] = cost[i][j] + 1;
                maxCost = std::max(cost[i-1][j], maxCost);
                q.push({i-1, j});
                freshCount--;
            }
            if (j > 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                cost[i][j-1] = cost[i][j] + 1;
                maxCost = std::max(cost[i][j-1], maxCost);
                q.push({i, j-1});
                freshCount--;
            }
            if (i < n-1 && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                cost[i+1][j] = cost[i][j] + 1;
                maxCost = std::max(cost[i+1][j], maxCost);
                q.push({i+1, j});
                freshCount--;
            }
            if (j < m-1 && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                cost[i][j+1] = cost[i][j] + 1;
                maxCost = std::max(cost[i][j+1], maxCost);
                q.push({i, j+1});
                freshCount--;
            }
        }
        
        //std::cout << freshCount << std::endl;
        if (freshCount == 0) {
            return maxCost;
        } else {
            return -1;
        }
    }
};
