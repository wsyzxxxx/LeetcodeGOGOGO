class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int dest = n * n;
        
        std::queue<int> q;
        std::vector<int> dp(dest+1, std::numeric_limits<int>::max());
        dp[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j = 1; j <= 6 && i + j <= dest; j++) {
                int num = i+j;
                int row = n - 1 - (num-1) / n;
                int col = (((n - 1 - row) & 1) == 0) ? ((num-1) % n) : (n - 1 - (num-1) % n);
                if (board[row][col] != -1) {
                    int next = board[row][col];
                    if (dp[next] > dp[i] + 1) {
                        q.push(next);
                    }
                    dp[next] = std::min(dp[next], dp[i] + 1);
                } else {
                    if (dp[num] > dp[i] + 1) {
                        q.push(num);
                    }
                    dp[num] = std::min(dp[num], dp[i] + 1);
                }
                //std::cout << num << " row: " << row << " col: " << col << " dp:" << dp[num] << std::endl;
            }
        }
        
        if (dp[dest] != std::numeric_limits<int>::max()) {
            return dp[dest];
        }
        return -1;
    }
};
