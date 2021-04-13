class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        int maxSize = 0;
        int currLength = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else {
                count--;
            }
            currLength++;
            if (count == 0) {
                maxSize = std::max(maxSize, currLength);
            } else if (count < 0) {
                count = 0;
                currLength = 0;
            }
        }
        count = currLength = 0;
        
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '(') {
                count++;
            } else {
                count--;
            }
            currLength++;
            if (count == 0) {
                maxSize = std::max(maxSize, currLength);
            } else if (count > 0) {
                count = 0;
                currLength = 0;
            }
        }
        
        return maxSize;
    }
};