class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int tempX = x;
        long rest = 0;
        while (tempX) {
            rest = rest * 10 + tempX % 10;
            tempX /= 10;
        }
        
        return (x == rest);
    }
};
