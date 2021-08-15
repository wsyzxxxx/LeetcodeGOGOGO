class Solution {
private:
    int makeIndex(int i, int j, int index) {
        return i * 1000 + j;
    }
    int dfs(vector<vector<int>>& grid, int i, int j, int index) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) {
            return 0;
        }
        if (grid[i][j] != 1) {
            return 0;
        }
        
        grid[i][j] = index;
        //std::cout << "assn: " << i << " " << j << " " << index << std::endl;
        return 1 + dfs(grid, i-1, j, index)
                 + dfs(grid, i+1, j, index)
                 + dfs(grid, i, j-1, index)
                 + dfs(grid, i, j+1, index);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        std::unordered_map<int, int> indexToSize;
        
        indexToSize[0] = 0;
        indexToSize[1] = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, indexToSize.size());
                    //std::cout << indexToSize.size() << std::endl;
                    //std::cout << i << " @ " << j << " " << st.size() << std::endl;
                    indexToSize[indexToSize.size()] = size;
                }
            }
        }
        
        int maxSize = 0;
        
        for (const auto & isz : indexToSize) {
            maxSize = std::max(maxSize, isz.second);
        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    std::unordered_set<int> st;
                    
                    if (i > 0) {
                        st.insert(grid[i-1][j]);
                    }
                    if (j > 0) {
                        st.insert(grid[i][j-1]);
                    }
                    if (i < grid.size()-1) {
                        st.insert(grid[i+1][j]);
                    }
                    if (j < grid[i].size()-1) {
                        st.insert(grid[i][j+1]);
                    }
                    
                    int size = 1;
                    for (int index : st) {
                        size += indexToSize[index];
                        //std::cout << index << std::endl;
                    }
                    //std::cout << i << " " << j << " " << size << std::endl;
                    maxSize = std::max(size, maxSize);
                }
            }
        }
        
        return maxSize;
    }
};