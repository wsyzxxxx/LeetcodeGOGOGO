class Solution {
private:
    int mod = 1e9 + 7;
    int dp[102][2][2];
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        
        if (m == 0 || n == 0) {
            return {0, 0};
        }
        
        std::memset(dp, 0, sizeof(dp));
        dp[n-1][0][0] = 0;
        dp[n-1][0][1] = 1;
        for (int i = m-2; i >= 0; i--) {
            dp[i][0][0] = board[n-1][i] == 'X' || dp[i+1][0][1] == 0 ? 0 : dp[i+1][0][0] + board[n-1][i] - '0';
            dp[i][0][1] = board[n-1][i] == 'X' ? 0 : dp[i+1][0][1];
        }
        
        int currLevel = 1;
        int lastLevel = 0;
        for (int i = n-2; i >= 0; i--) {
            dp[m-1][currLevel][0] = board[i][m-1] == 'X' || dp[m-1][lastLevel][1] == 0 ? 0 : dp[m-1][lastLevel][0] + board[i][m-1] - '0';
            dp[m-1][currLevel][1] = board[i][m-1] == 'X' ?  0 : dp[m-1][lastLevel][1];
            
            for (int j = m-2; j >= 0; j--) {
                if (board[i][j] == 'X') {
                    dp[j][currLevel][0] = 0;
                    dp[j][currLevel][1] = 0;
                } else {
                    int mx = std::max(dp[j+1][currLevel][0], std::max(dp[j][lastLevel][0], dp[j+1][lastLevel][0]));
                    dp[j][currLevel][1] = 0;
                    if (mx == dp[j+1][currLevel][0]) {
                        dp[j][currLevel][1] += dp[j+1][currLevel][1] % mod;
                    }
                    if (mx == dp[j][lastLevel][0]) {
                        dp[j][currLevel][1] += dp[j][lastLevel][1] % mod;
                    }
                    if (mx == dp[j+1][lastLevel][0]) {
                        dp[j][currLevel][1] += dp[j+1][lastLevel][1] % mod;
                    }
                    dp[j][currLevel][0] = mx + board[i][j] - '0';
                    
                }
            }
            currLevel = 1 - currLevel;
            lastLevel = 1 - lastLevel;
        }
        return {dp[0][lastLevel][1] == 0 ? 0 : dp[0][lastLevel][0] - 21, dp[0][lastLevel][1] % mod};
    }
};
