class Solution {
public:
    string addStrings(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        
        std::string result;
        char rest = 0;
        char n;
        for (int i = 0; i < num1.size() || i < num2.size(); i++) {
            if (i < num1.size() && i < num2.size()) {
                n = (char)(num1[i] + num2[i] + rest - '0');
            } else if (i < num1.size()) {
                n = (char)(num1[i] + rest);
            } else {
                n = (char)(num2[i] + rest);
            }
            if (n > '9') {
                rest = 1;
                n -= (char)('9' + 1 - '0');
            } else {
                rest = 0;
            }
            result += n;
        }
        if (rest) {
            result += '1';
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};