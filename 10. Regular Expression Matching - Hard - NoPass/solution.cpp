class Solution {
public:
    bool isMatch(string s, string p) {
        // if (p.empty()) {
        //     return false;
        // }
//         if (s.empty()) {
            
//         }
        
        std::vector<std::vector<bool> > dp(s.size()+1, std::vector<bool>(p.size()+1, false));
        
        dp[s.size()][p.size()] = true;
        for (int i = p.size(); i >= 0; i--) {
            if (i < p.size() && p[i+1] == '*' && dp[s.size()][i+2]) {
                dp[s.size()][i] = true;
            }
        }
        
        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = p.size()-1; j >= 0; j--) {
                bool match = (s[i] == p[j] || p[j] == '.');
                if (j+1 < p.size() && p[j+1] == '*') {
                    dp[i][j] = dp[i+1][j] && match || dp[i][j+2];
                } else {
                    dp[i][j] = dp[i+1][j+1] && match;
                }
                
            }
        }
        
        
        return dp[0][0];
    }
};
