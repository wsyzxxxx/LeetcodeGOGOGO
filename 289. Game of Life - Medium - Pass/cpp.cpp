class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool isLiveNow = board[i][j] == 1;
                int liveNeighbours = 0;
                liveNeighbours += (i > 0   && j > 0   && board[i-1][j-1] > 0) ? 1 : 0;
                liveNeighbours += (i > 0   &&            board[i-1][j] > 0) ? 1 : 0;
                liveNeighbours += (i > 0   && j < m-1 && board[i-1][j+1] > 0) ? 1 : 0;
                liveNeighbours += (j > 0   &&            board[i][j-1] > 0) ? 1 : 0;
                liveNeighbours += (j < m-1 &&            board[i][j+1] > 0) ? 1 : 0;
                liveNeighbours += (i < n-1 && j < m-1 && board[i+1][j+1] > 0) ? 1 : 0;
                liveNeighbours += (i < n-1 &&            board[i+1][j] > 0) ? 1 : 0;
                liveNeighbours += (i < n-1 && j > 0   && board[i+1][j-1] > 0) ? 1 : 0;
                
                if (liveNeighbours < 2 && isLiveNow) {
                    board[i][j] = 2;
                } else if (liveNeighbours > 3 && isLiveNow) {
                    board[i][j] = 2;
                } else if (liveNeighbours == 3 && !isLiveNow) {
                    board[i][j] = -1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                } else if (board[i][j] == 2) {
                    board[i][j] = 0;
                }
            }
        }
        

    }
};
