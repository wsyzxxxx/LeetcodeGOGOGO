class Solution {
public:
    int countSubstrings(string s) {
        size_t len = s.size();
        int res = 0;
        
        bool dp[len][len] = {false};
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                
                dp[i][j] = (s[i] == s[j]) &&
                           (i - j < 3 || dp[i-1][j+1]);
                if (dp[i][j]) {
                    res++;
                }
            }
        }
        
        return res;
    }
};
