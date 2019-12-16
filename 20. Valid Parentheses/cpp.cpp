class Solution {
public:
    bool isValid(string s) {
        std::stack<int> charStack;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                charStack.push(1);
            } else if (s[i] == '{') {
                charStack.push(2);
            } else if (s[i] == '[') {
                charStack.push(3);
            } else if (s[i] == ')' && !charStack.empty()) {
                if (charStack.top() == 1) {
                    charStack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}' && !charStack.empty()) {
                if (charStack.top() == 2) {
                    charStack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']' && !charStack.empty()) {
                if (charStack.top() == 3) {
                    charStack.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        if (charStack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
