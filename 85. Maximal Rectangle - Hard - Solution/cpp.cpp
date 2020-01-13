class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
             return 0;
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        std::vector<int> heights(m+1, 0);
        std::stack<int> s;
        
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //int currH = (matrix[i][j] == '1') ? 1 : 0;
                heights[j] = (matrix[i][j] == '0') ? 0 : 1 + heights[j];
            }
            
            for (int j = 0; j < m+1; j++) {
                while (!s.empty() && heights[s.top()] >= heights[j]) {
                    int currIndex = s.top();
                    s.pop();
                    
                    int left = s.empty() ? -1 : s.top();
                    maxArea = std::max(maxArea, (j - left - 1) * heights[currIndex]);
                }
                s.push(j);
            }
            while (!s.empty()) {
                s.pop();
            }
        }
        
        return maxArea;
    }
};
