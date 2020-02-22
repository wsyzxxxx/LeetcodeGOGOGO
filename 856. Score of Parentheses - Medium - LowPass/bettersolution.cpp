class Solution {
public:
    int scoreOfParentheses(string S) {
        int n = S.length();
        
        if (n == 0) {
            return 0;
        }
        
        int bal = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] == '(') {
                bal++;
            } else {
                bal--;
                if (S[i-1] == '(') {
                    res += 1 << bal;
                }
            }
        }
        
        return res;
    }
};
