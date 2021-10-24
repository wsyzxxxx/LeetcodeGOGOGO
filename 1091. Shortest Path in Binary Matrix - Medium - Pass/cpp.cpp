const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty() || grid[0][0] != 0 || grid.back().back() != 0) {
            return -1;
        }
        
        std::queue<std::pair<int, int>> q;
        q.push({0, 0});
        int step = 1;
        
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x == grid.size()-1 && y == grid[x].size()-1) {
                    return step;
                }
                
                for (int k = 0; k < 8; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if (nx < 0 || ny < 0 || 
                        nx >= grid.size() || 
                        ny >= grid[nx].size() || 
                        grid[nx][ny] != 0) {
                        continue;
                    }
                    
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            
            step++;
        }
        
        return -1;
    }
};