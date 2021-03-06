class Solution {
private:
    int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        
        if (n < 1) {
            return 0;
        }
        
        std::vector<int> leftLess(n), rightLess(n);
        std::stack<int> leftS, rightS;
        
        for (int i = 0; i < n; i++) {
            while (!leftS.empty() && A[leftS.top()] > A[i]) {
                leftS.pop();
            }
            leftLess[i] = leftS.empty() ? i + 1 : i - leftS.top();
            leftS.push(i);
        }
        
        for (int i = n-1; i >= 0; i--) {
            while (!rightS.empty() && A[rightS.top()] >= A[i]) {
                rightS.pop();
            }
            rightLess[i] = rightS.empty() ? n - i : rightS.top() - i;
            rightS.push(i);
        }
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (A[i] * leftLess[i] * rightLess[i]) % mod;
            //std::cout << "i: " << i << " left:" << leftLess[i] << " right:" << rightLess[i] << std::endl;
        }
        
        return sum % mod;
    }
};
