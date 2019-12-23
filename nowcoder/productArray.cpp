class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        std::vector<int> res(A.size(), 1);
        if (A.empty()) {
            return res;
        }
        for (int i = 1; i < A.size(); i++) {
            res[i] = A[i-1] * res[i-1]; 
        }
        int mul = 1;
        for (int i = A.size()-1; i >= 0; i--) {
            res[i] = res[i] * mul;
            mul = mul * A[i];
        }
        
        return res;
    }
};
