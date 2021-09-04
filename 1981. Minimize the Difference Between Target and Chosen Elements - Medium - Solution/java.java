class Solution {
    public int minimizeTheDifference(int[][] mat, int target) {
        boolean[][] dp = new boolean[mat.length][5000];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], false);
        }
        
        for (int i = 0; i < mat[0].length; i++) {
            dp[0][mat[0][i]] = true;
        }
        
        for (int i = 1; i < mat.length; i++) {
            for (int j = 0; j < 5000; j++) {
                if (dp[i-1][j]) {
                    for (int k = 0; k < mat[i].length; k++) {
                        dp[i][j + mat[i][k]] = true;
                    }
                }
            }
        }
        
        int minDiff = 5005;
        
        for (int i = 1; i < 5000; i++) {
            if (dp[mat.length-1][i]) {
                minDiff = Math.min(minDiff, Math.abs(target - i));
            }
        }
        
        return minDiff;
    }
}