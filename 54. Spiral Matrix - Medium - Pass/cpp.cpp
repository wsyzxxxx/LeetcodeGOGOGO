class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        
        int up = 0;
        int low = matrix.size();
        int left = 0;
        int right = matrix[0].size();
        std::vector<int> res;
        while (up < low || left < right) {
            if (up < low) {
                for (int i = left; i < right; i++) {
                    res.push_back(matrix[up][i]);
                }
                up++;
            }
            if (left < right) {
                for (int i = up; i < low; i++) {
                    res.push_back(matrix[i][right-1]);
                }
                right--;
            }
            if (up < low) {
                for (int i = right-1; i >= left; i--) {
                    res.push_back(matrix[low-1][i]);
                }
                low--;
            }
            if (left < right) {
                for (int i = low-1; i >= up; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return res;
    }
};
