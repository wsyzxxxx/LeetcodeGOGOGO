//bool dp[1002][1002];

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        
        //std::string res;
        //std::vector<std::vector<bool> > dp(1002, std::vector<bool>(1002, false));
        int maxlen = 1;
        int maxStart = 1;
        for (int i = 0; i < s.size(); ) {
            if (s.size() - i < maxlen/2) {
                break;
            }
            
            int start = i;
            int end = i;
            
            while (end < s.size()-1 && s[end+1] == s[end]) {
                end++;
            }
            
            i = end + 1;
            
            while (start > 0 && end < s.size()-1 && s[start-1] == s[end+1]) {
                start--;
                end++;
            }
            
            if (end - start + 1 > maxlen) {
                maxlen = end - start + 1;
                maxStart = start;
            }
        }
        
        
        return s.substr(maxStart, maxlen);
    }
};
