class Solution {
private:
    int mod = 1e9 + 7;
public:
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        
        if (n == 0) {
            return 0;
        }
        
        std::sort(A.begin(), A.end());
        
        long long sum = 0;
        long long coe = 1;
        for (int i = 0; i < n; i++) {
            sum = (sum + A[i] * coe - A[n-1-i] * coe) % mod;
            coe = coe * 2 % mod;
        }
        
        return sum % mod;
    }
};
