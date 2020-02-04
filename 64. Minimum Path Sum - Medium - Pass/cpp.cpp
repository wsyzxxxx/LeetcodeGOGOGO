class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        int n = grid.size();
        int m = grid[0].size();
        int dp[m][2];
        
        dp[0][0] = grid[0][0];
        int currLevel = 0;

        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            currLevel = 1 - currLevel;
            dp[0][currLevel] = dp[0][1-currLevel] + grid[i][0];
            for (int j = 1; j < m; j++) {
                dp[j][currLevel] = std::min(dp[j-1][currLevel], dp[j][1-currLevel]) + grid[i][j];
            }
        }

        return dp[m-1][currLevel];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        int n = grid.size();
        int m = grid[0].size();
        int dp[m];
        
        dp[0] = grid[0][0];
        //int currLevel = 0;

        for (int i = 1; i < m; i++) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            //currLevel = 1 - currLevel;
            //dp[0][currLevel] = dp[0][1-currLevel] + grid[i][0];
            dp[0] = dp[0] + grid[i][0];
            for (int j = 1; j < m; j++) {
                //dp[j][currLevel] = std::min(dp[j-1][currLevel], dp[j][1-currLevel]) + grid[i][j];
                dp[j] = std::min(dp[j-1], dp[j]) + grid[i][j];
            }
        }

        return dp[m-1];
    }
};