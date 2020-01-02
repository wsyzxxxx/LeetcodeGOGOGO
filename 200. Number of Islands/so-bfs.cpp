class Solution {
private:
    void reFill(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[i].size() ||
            grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        reFill(grid, i-1, j);
        reFill(grid, i+1, j);
        reFill(grid, i, j-1);
        reFill(grid, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    reFill(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
