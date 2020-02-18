class Solution {
private:
    
//     int checkPalindrome(int start, int end, std::string & s,
//                         std::vector<std::vector<int> > & isPalin) {
//         if (isPalin[start][end] != -1) {
//             return isPalin[start][end] == 1;
//         }
//         int & temp = isPalin[start][end];
//         while (start < end) {
//             if (s[start++] != s[end--]) {
//                 temp = 0;
//                 return false;
//             }
//         }
//         temp = 1;
//         return true;
//     }
public:
    int minCut(string s) {
        int n = s.size();
        if (n < 2) {
            return 0;
        }
        
        std::vector<int> dp(n+1, -1);
        std::vector<std::vector<bool> > isPalin(n+1, std::vector<bool>(n+1, false));
        
        for (int i = 0; i <= n; i++) {
            dp[i] = i-1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[i-1] == s[j] && (i - j - 1 < 2 || isPalin[j+1][i-2])) {
                    isPalin[j][i-1] = true;
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};
