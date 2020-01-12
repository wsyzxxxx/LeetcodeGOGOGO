class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int pre = 1;
        int prepre = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                pre = 0;
            }
            
            if (s[i-1] == '1' || (s[i-1]) == '2' && s[i] <= '6') {
                pre += prepre;
                prepre = pre - prepre;
            } else {
                prepre = pre;
            }
        }
        
        return pre;
    }
};
