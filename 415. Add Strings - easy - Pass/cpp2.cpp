class Solution {
public:
    string addStrings(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        
        std::string result;
        int rest = 0;
        for (int i = 0; i < num1.size() || i < num2.size() || rest > 0; i++) {
            if (i < num1.size()) {
                rest += num1[i] - '0';
            }
            if (i < num2.size()) {
                rest += num2[i] - '0';
            }
            
            result += rest % 10 + '0';
            rest /= 10;
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};