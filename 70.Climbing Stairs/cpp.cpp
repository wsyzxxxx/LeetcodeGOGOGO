class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) 
            return 1;
        
        int curr = 1;
        int next = 2;
        for (int i = 3; i <= n; i++) {
            int third = curr + next;
            curr = next;
            next = third;
        }
        
        return next;
    }
};
