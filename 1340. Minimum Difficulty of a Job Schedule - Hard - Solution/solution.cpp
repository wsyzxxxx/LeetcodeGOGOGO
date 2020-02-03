class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) {
            return -1;
        }
        
        int dp[12][305];
        std::memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        
        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= jobDifficulty.size(); j++) {
                int mx = jobDifficulty[j - 1];
                for (int prev = j - 1; prev >= 0; prev--) {
                    if (dp[i-1][prev] != -1) {
                        if (dp[i][j] == -1 || dp[i][j] > mx + dp[i-1][prev]) {
                            dp[i][j] = dp[i-1][prev] + mx;
                        }
                    }
                        
                    if (prev > 0) {
                        mx = std::max(mx, jobDifficulty[prev - 1]);
                    }
                }
            }
        }
        
        return dp[d][jobDifficulty.size()];
    }
};
