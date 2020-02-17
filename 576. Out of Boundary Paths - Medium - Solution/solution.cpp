class Solution {
private:
    int dp[52][52][52];
    int mod = 1e9 + 7;
    
//     int judgeBoarder(int i, int j, int m, int n) {
//         int res = 0;
//         res += i == 0;
//         res += j == 0;
//         res += i == m;
//         res += j == n;
        
//         return res;
//     }
    int search(int i, int j, int m, int n, int N) {
        if (i == m || j == n || i < 0 || j < 0) {
            return 1;
        }
        if (N == 0) {
            return 0;
        }
        
        if (dp[i][j][N] != -1) {
            return dp[i][j][N];
        }
        
        dp[i][j][N] = (
            (search(i-1, j  , m, n, N-1) + search(i  , j-1, m, n, N-1)) % mod +
            (search(i+1, j  , m, n, N-1) + search(i  , j+1, m, n, N-1)) % mod) % mod;
        return dp[i][j][N];
    }
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) {
            return 0;
        }
        
        std::memset(dp, -1, sizeof(dp));
        
        return search(i, j, m, n, N);
    }
};
