class Solution {
private:
    int calculate(int n, long n1, long n2) {
        long steps = 0;
        while (n1 <= n) {
            steps += std::min((long)n+1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        if (n < 10) {
            return k;
        }
        
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = calculate(n, curr, curr+1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
};
