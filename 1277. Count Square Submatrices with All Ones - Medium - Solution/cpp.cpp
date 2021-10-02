class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i == 0 || j == 0) {
                    res += matrix[i][j];
                } else if (matrix[i][j] == 1) {
                    matrix[i][j] = std::min(matrix[i-1][j], std::min(matrix[i][j-1], matrix[i-1][j-1])) + 1;
                    res += matrix[i][j];
                }
            }
        }
        
        return res;
    }
};