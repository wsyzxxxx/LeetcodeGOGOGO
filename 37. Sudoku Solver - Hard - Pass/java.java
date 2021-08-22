class Solution {
    private boolean dfs(char[][] board, boolean[][] rows, boolean[][] cols,
                        boolean[][] blocks, int i, int j) {
        if (j == 9) {
            j = 0;
            i++;
        }
        if (i == 9) {
            return true;
        }
        
        if (board[i][j] != '.') {
            return dfs(board, rows, cols, blocks, i, j+1);
        }
        
        for (int k = 1; k <= 9; k++) {
            if (rows[i][k] == false && cols[j][k] == false && blocks[i/3*3+j/3][k] == false) {
                rows[i][k] = true;
                cols[j][k] = true;
                blocks[i/3*3+j/3][k] = true;
                
                //System.out.println("assn: " + i + " " + j + " " + k);
                board[i][j] = (char)(k + '0');
                if (dfs(board, rows, cols, blocks, i, j+1)) {
                    return true;
                }
                board[i][j] = '.';
                
                rows[i][k] = false;
                cols[j][k] = false;
                blocks[i/3*3+j/3][k] = false;
            }
        }
        
        return false;
    }
    public void solveSudoku(char[][] board) {
        boolean[][] rows = new boolean[9][10];
        boolean[][] cols = new boolean[9][10];
        boolean[][] blocks = new boolean[9][10];
        
        for (int i = 0; i < 9; i++) {
            Arrays.fill(rows[i], false);
            Arrays.fill(cols[i], false);
            Arrays.fill(blocks[i], false);
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rows[i][board[i][j] - '0'] = true;
                    cols[j][board[i][j] - '0'] = true;
                    blocks[i/3*3+j/3][board[i][j] - '0'] = true;
                }
            }
        }
        
        dfs(board, rows, cols, blocks, 0, 0);
    }
}