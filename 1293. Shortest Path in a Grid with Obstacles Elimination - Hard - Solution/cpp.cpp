const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int dp[50][50][2];

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if (grid.size() == 1 && grid[0].size() == 1) {
            return 0;
        }
        
        std::memset(dp, -1, sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        std::queue<std::vector<int>> q;
        q.push({0, 0, k, 0});
        dp[0][0][0] = 0;
        dp[0][0][1] = k;
        
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int rest = q.front()[2];
            int d = q.front()[3];
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = dx[k] + x;
                int ny = dy[k] + y;
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                
                int nrest = rest - grid[nx][ny];
                
                if (nrest < 0) {
                    continue;
                }
                
                if (dp[nx][ny][0] == -1 || d+1 < dp[nx][ny][0] || dp[nx][ny][1] < nrest) {
                    dp[nx][ny][0] = dp[nx][ny][0] == -1 ? d+1 : std::min(d+1, dp[nx][ny][0]);
                    dp[nx][ny][1] = std::max(dp[nx][ny][1], nrest);
                    q.push({nx, ny, nrest, d+1});
                }
            }
        }
        
        return dp[n-1][m-1][0];
    }
};