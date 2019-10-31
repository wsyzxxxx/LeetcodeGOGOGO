class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        
        if (x == INT_MIN)
            return 0;
        
        if (x < 0) {
            x = -x;
            flag = true;
        }
        
        long long temp = 0;
        int bit;
        
        while (x) {
            bit = x % 10;
            x /= 10;
            temp = temp * 10 + bit;
        }
        
        if (flag) {
            if (temp > (long long)INT_MAX + 1)
                return 0;
            else
                return (int)-temp;
        } else {
            if (temp > (long long)INT_MAX)
                return 0;
            else
                return (int)temp;
        }
    }
};
