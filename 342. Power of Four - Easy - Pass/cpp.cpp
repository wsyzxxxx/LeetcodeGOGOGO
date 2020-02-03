class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        while (num > 4) {
            if (num & 3) {
                return false;
            }
            num = num >> 2;
        }
        
        return num == 4;
    }
};
