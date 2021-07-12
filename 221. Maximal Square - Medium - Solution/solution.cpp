int dp[305][305];

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        std::memset(dp, 0, sizeof(dp));
        
        int maxSize = 0;
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxSize = std::max(maxSize, dp[i][0]);
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
            maxSize = std::max(maxSize, dp[0][i]);
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    maxSize = std::max(maxSize, dp[i][j] * dp[i][j]);
                }
            }
        }
        
        return maxSize;
    }
};