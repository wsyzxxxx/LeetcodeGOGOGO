class NumMatrix {
private:
    std::vector<std::vector<int> > sums;
public:
    NumMatrix(vector<vector<int>>& matrix) : sums(std::vector<std::vector<int> >(matrix.size(), std::vector<int>(matrix[0].size(), 0))) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i == 0 && j == 0) {
                    sums[i][j] = matrix[i][j];
                } else if (j == 0) {
                    sums[i][j] = sums[i-1][j] + matrix[i][j];
                } else if (i == 0) {
                    sums[i][j] = sums[i][j-1] + matrix[i][j];
                } else {
                    sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sums[row2][col2];
        
        if (row1 > 0) {
            sum -= sums[row1-1][col2];
        }
        if (col1 > 0) {
            sum -= sums[row2][col1-1];
        }
        if (row1 > 0 && col1 > 0) {
            sum += sums[row1-1][col1-1];
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */