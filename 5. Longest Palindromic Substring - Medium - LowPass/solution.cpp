bool dp[1002][1002];

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        
        //std::string res;
        //std::vector<std::vector<bool> > dp(1002, std::vector<bool>(1002, false));
        int maxlen = 0;
        int start = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i+1][j-1]);
                
                if (dp[i][j] && j-i+1 > maxlen) {
                    maxlen = j-i+1;
                    start = i;
                }
            }
            
            if (s.size() - i < maxlen/2) {
                break;
            }
        }
        
        return s.substr(start, maxlen);
    }
};
