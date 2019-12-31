class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        if (N == 1) {
            return 1;
        }
        if (N == 2) {
            return 1;
        }
        
        int one = 1;
        int two = 1;
        for (int i = 3; i <= N; i++) {
            int third = one + two;
            one = two;
            two = third;
        }
        
        return two;
    }
};
