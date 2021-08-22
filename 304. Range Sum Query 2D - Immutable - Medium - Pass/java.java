class NumMatrix {
    int[][] sum;
    public NumMatrix(int[][] matrix) {
        sum = new int[matrix.length+1][matrix[0].length+1];
        for (int i = 0; i <= matrix.length; i++) {
            for (int j = 0; j <= matrix[0].length; j++) {
                if (i == 0 || j == 0) {
                    sum[i][j] = 0;
                } else {
                    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
                }
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */