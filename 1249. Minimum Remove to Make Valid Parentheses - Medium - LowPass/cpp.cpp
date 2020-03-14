class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.empty()) {
            return s;
        }
        
        int leftCount = 0;
        std::string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && leftCount == 0) {
                continue;
            }
            if (s[i] == ')') {
                res += s[i];
                leftCount--;
            } else if (s[i] == '(') {
                res += s[i];
                leftCount++;
            } else {
                res += s[i];
            }
        }
        
        int i = res.size()-1;
        while (leftCount) {
            if (res[i] == '(') {
                res = res.substr(0, i) + res.substr(i+1);
                leftCount--;
            }
            i--;
        }
        
        return res;
    }
};
