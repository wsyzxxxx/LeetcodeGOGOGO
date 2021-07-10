const int MOD = 1e9 + 7;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        
        long long before = 1;
        long long last = 0;
        long long curr = 0;
        if (s[0] != '*') {
            last = curr = 1;
        } else {
            last = curr = 9;
        }
        for (int i = 1; i < s.size(); i++) {
            curr = 0;
            if (s[i] == '*') {
                curr += last * 9 % MOD;
            } else if (s[i] != '0') {
                curr += last;
            }
            if (s[i-1] == '*') {
                if (s[i] == '*') {
                    curr += before * 15 % MOD;
                } else if (s[i] <= '6') {
                    curr += before * 2 % MOD;
                } else {
                    curr += before;
                }
            } else if (s[i-1] == '1') {
                if (s[i] == '*') {
                    curr += before * 9 % MOD;
                } else {
                    curr += before;
                }
            } else if (s[i-1] == '2') {
                if (s[i] == '*') {
                    curr += before * 6 % MOD;
                } else if (s[i] <= '6') {
                    curr += before;
                }
            }
            
            before = last;
            last = curr;
        }
        
        return curr % MOD;
    }
};