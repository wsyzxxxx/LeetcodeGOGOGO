class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::string tmp;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && count == 0) {
                continue;
            } else if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }
            tmp += s[i];
        }
        
        std::string result;
        count = 0;
        for (int i = tmp.size()-1; i >= 0; i--) {
            if (tmp[i] == '(' && count == 0) {
                continue;
            } else if (tmp[i] == '(') {
                count++;
            } else if (tmp[i] == ')') {
                count--;
            }
            result += tmp[i];
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};