class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int index = 0;
        while (index < s.size() && s[index] == ' ') {
            index++;
        }
        
        long long flag = 1;
        if (s[index] == '-') {
            flag = -1;
            index++;
        } else if (s[index] == '+') {
            index++;
        }
        
        int count = 0;
        while (index < s.size() && std::isdigit(s[index])) {
            count++;
            num = num * 10 + s[index++] - '0';
            if (num-1 > INT_MAX) {
                break;
            }
        }
        if (count == 0) {
            return 0;
        }
        
        num *= flag;
        if (num < INT_MIN) {
            num = INT_MIN;
        }
        if (num > INT_MAX) {
            num = INT_MAX;
        }
        return num;
    }
};