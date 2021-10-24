int memo[1028];

class Solution {
private:
    int result;
    int dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes, int index, int mask, int curr) {
        if (index == workers.size()) {
            return 0;
        }
        
        if (memo[mask] != -1) {
            return memo[mask];
        }
        
        memo[mask] = INT_MAX;
        for (int i = 0; i < bikes.size(); i++) {
            if (((1 << i) & mask) == 0) {
                int dist = std::abs(workers[index][0] - bikes[i][0]) +
                    std::abs(workers[index][1] - bikes[i][1]);
                memo[mask] = std::min(memo[mask], 
                    dist + dfs(workers, bikes, index+1, mask | (1<<i), curr+dist));
            }
        }
        
        return memo[mask];
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        std::memset(memo, -1, sizeof(memo));
        
        return dfs(workers, bikes, 0, 0, 0);
    }
};