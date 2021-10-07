class Solution {
    public int[][] matrixBlockSum(int[][] matrix, int k) {
        int[][] sum = new int[matrix.length+1][matrix[0].length+1];
        for (int i = 0; i <= matrix.length; i++) {
            for (int j = 0; j <= matrix[0].length; j++) {
                if (i == 0 || j == 0) {
                    sum[i][j] = 0;
                } else {
                    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
                }
            }
        }
        
        int[][] result = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                int left = Math.max(0, j-k);
                int right = Math.min(matrix[i].length, j+k+1);
                int up = Math.max(0, i-k);
                int down = Math.min(matrix.length, i+k+1);
                // System.out.println(down + " " + right + " " + sum[down][right] + " " + sum[up][right] + " " + sum[down][left] + " " + sum[left][right]);
                result[i][j] = sum[down][right] - sum[up][right] - sum[down][left] + sum[up][left];
            }
        }
        
        return result;
    }
}