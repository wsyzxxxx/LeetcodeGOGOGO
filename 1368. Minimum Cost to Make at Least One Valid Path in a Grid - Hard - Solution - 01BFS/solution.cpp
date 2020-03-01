int cost[102][102];
std::deque<std::pair<int, int> > dq;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        while (!dq.empty()) {
            dq.pop_back();
        }
        
        int n = grid.size();
        int m = grid[0].size();
        std::memset(cost, -1, sizeof(cost));
        //visited[0][0] = true;
        cost[0][0] = 0;
        dq.push_back({0, 0});
        
        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();
            //std::cout << x << " " << y << " " << cost[x][y] << std::endl;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nCost = cost[x][y] + 1;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    //std::cout << "#" << nx << " " << ny << " " << dx[i] << " " << dy[i] << " " << cost[nx][ny] << std::endl;
                    if (i+1 == grid[x][y] && (cost[nx][ny] == -1 || cost[nx][ny] > nCost-1)) {
                        cost[nx][ny] = nCost - 1;
                        dq.push_front({nx, ny});
                    } else if (cost[nx][ny] == -1 || cost[nx][ny] > nCost) {
                        cost[nx][ny] = nCost;
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
        
        return cost[n-1][m-1];
    }
};
