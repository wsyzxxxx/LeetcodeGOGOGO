class Solution {
private:
    int dp[1002][1002][4];
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        //std::string dp[1002][1002];
        //std::vector<std::vector<std::string> > dp(n+1, std::vector<std::string>(m+1));
        // for (int i = 0; i < 1002; i++) {
        //     for (int j = 0; j < 1002; j++) {
        //         dp[i][j].clear();
        //     }
        // }
        std::memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            dp[i][0][0] = str1[i-1];
            dp[i][0][1] = i;
            dp[i][0][2] = i-1;
            dp[i][0][3] = 0;
        }
        for (int i = 1; i <= m; i++) {
            dp[0][i][0] = str2[i-1];
            dp[0][i][1] = i;
            dp[0][i][2] = 0;
            dp[0][i][3] = i-1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str1[i] == str2[j]) {
                    dp[i+1][j+1][0] = str1[i];
                    dp[i+1][j+1][1] = dp[i][j][1] + 1;
                    dp[i+1][j+1][2] = i;
                    dp[i+1][j+1][3] = j;
                } else {
                    if (dp[i+1][j][1] < dp[i][j+1][1]) {
                        dp[i+1][j+1][0] = str2[j];
                        dp[i+1][j+1][1] = dp[i+1][j][1] + 1;
                        dp[i+1][j+1][2] = i+1;
                        dp[i+1][j+1][3] = j;
                    } else {
                        dp[i+1][j+1][0] = str1[i];
                        dp[i+1][j+1][1] = dp[i][j+1][1] + 1;
                        dp[i+1][j+1][2] = i;
                        dp[i+1][j+1][3] = j+1;
                    }
                }
                // std::cout << i+1 << " " << j+1 << " " << (char)dp[i+1][j+1][0] << " "  << dp[i+1][j+1][1]<< " " << dp[i+1][j+1][2] << " " << dp[i+1][j+1][3] << std::endl;
            }
        }
        std::string res = "";
        for (int i = n, j = m; i != 0 || j != 0; ) {
            res = (char)dp[i][j][0] + res;
            int nexti = dp[i][j][2];
            int nextj = dp[i][j][3];
            i = nexti;
            j = nextj;
        }
        //res = (char)dp[0][0][0];
        
        return res;
    }
};
