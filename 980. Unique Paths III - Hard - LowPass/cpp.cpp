class Solution {
private:
    struct Point {
        int x;
        int y;
    };
    int res = 0;
    Point start;
    int squareCount = 0;
    void findAllPaths(std::vector<std::vector<int> > & grid,
                      int x,
                      int y,
                      int count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] < 0) {
            return;
        }
        //std::cout << x << " " << y << " " << count << std::endl;
        if (grid[x][y] == 2 && count == squareCount) {
            res++;
            return;
        }
        if (grid[x][y] != 0 && grid[x][y] != 1) {
            return;
        }
        
        grid[x][y] = -1;
        findAllPaths(grid, x-1, y, count+1);
        findAllPaths(grid, x+1, y, count+1);
        findAllPaths(grid, x, y-1, count+1);
        findAllPaths(grid, x, y+1, count+1);
        grid[x][y] = 0;
    }
                      
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        
        int obstacleCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                switch (grid[i][j]) {
                    case 1:
                        start.x = i;
                        start.y = j;
                        break;
                    case -1:
                        obstacleCount++;
                        break;
                    default:
                        break;
                }
            }
        }
        
        squareCount = m * n - obstacleCount - 1;
        
        findAllPaths(grid, start.x, start.y, 0);
        
        return res;
    }
};
