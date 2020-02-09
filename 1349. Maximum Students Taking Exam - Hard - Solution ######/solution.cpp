int dp[10][513];

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        if (seats.empty() || seats[0].empty()) {
            return 0;
        }
        
        int maxStu = 0;
        int n = seats.size();
        int m = seats[0].size();
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         std::cout << seats[i][j] << "  ";
        //     }
        //     std::cout << std::endl;
        // }
        
        std::memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        
        int M = 1 << m;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    if (dp[i-1][k] == -1) {
                        continue;
                    }
                    bool isMatch = true;
                    
                    int count = 0;
                    for (int curr = 0; curr < m; curr++) {
                        if ((j>>curr)&1) {
                            isMatch = isMatch && (
                                seats[i-1][curr] == '.' &&
                                (curr == 0   || (j>>(curr-1)&1) == 0) &&
                                (curr == m-1 || (j>>(curr+1)&1) == 0) &&
                                (i == 0      || curr == 0   || (k>>(curr-1)&1) == 0) &&
                                (curr == m-1 || (k>>(curr+1)&1) == 0));
                            count++;
                        }
                    }
                    
                    if (isMatch) {
                        if (count + dp[i-1][k] > dp[i][j]) {
                            //std::cout << i << " " << j << " " << k << " " << count + dp[i-1][k] << std::endl;
                            dp[i][j] = std::max(dp[i][j], count + dp[i-1][k]);
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < M; i++) {
            maxStu = std::max(maxStu, dp[n][i]);
        }
        
        return maxStu;
    }
};

/*
[["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]
[[".","#"],["#","#"],["#","."],["#","#"],[".","#"]]
[["#",".",".",".","#"],[".","#",".","#","."],[".",".","#",".","."],[".","#",".","#","."],["#",".",".",".","#"]]
*/
