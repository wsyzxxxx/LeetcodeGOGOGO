class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int[][] dp = new int[205][205];
        
        int n = dungeon.length;
        int m = dungeon[0].length;
        
        dp[n-1][m-1] = dungeon[n-1][m-1] >= 0 ? -1 : dungeon[n-1][m-1] - 1;
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (i == n-1 && j == m-1) {
                    continue;
                }
                if (j == m-1) {
                    dp[i][j] = dp[i+1][j] + dungeon[i][j];
                } else if (i == n-1) {
                    dp[i][j] = dp[i][j+1] + dungeon[i][j];
                } else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j+1]) + dungeon[i][j];
                }
                
                if (dp[i][j] >= 0) {
                    dp[i][j] = -1;
                }
            }
        }
        
        return -dp[0][0];
    }
}