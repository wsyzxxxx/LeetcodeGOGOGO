class Solution {
private:
    int nextNum(int n) {
        int res = 0;
        while (n) {
            res = res + (n%10)*(n%10);
            n /= 10;
        }
        
        return res;
    }
public:
    bool isHappy(int n) {
        int slow = nextNum(n);
        int fast = nextNum(nextNum(n));
        while (slow != fast) {
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }
        if (slow == 1) {
            return true;
        } else {
            return false;
        }
    }
};
