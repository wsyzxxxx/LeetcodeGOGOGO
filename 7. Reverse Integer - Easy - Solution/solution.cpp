class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        
        int res = 0;
        while (x) {
            if (res > std::numeric_limits<int>::max() / 10 ||
                res < std::numeric_limits<int>::min() / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return res;
    }
};
