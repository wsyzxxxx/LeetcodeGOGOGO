class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        long long base = 1;
        long long acc = 0;
        long long digits = 1;
        for (long long i = 9; acc + i * base < n; i *= 10, base++, digits *= 10) {
            acc += i * base;
        }
        
        n -= acc;
        long long count = n > 0 ? (n-1) / base : 0;
        long long num = digits + count;
        std::string numStr = std::to_string(num);
        
        return n > 0 ? numStr[(n-1)%base] - '0' : numStr[0] - '0';
    }
};