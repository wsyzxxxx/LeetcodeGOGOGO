class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty() || A.size() != B.size()) {
            return -1;
        }
        
        int numCounts[7];
        std::memset(numCounts, 0, sizeof(numCounts));
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) {
                numCounts[A[i]]++;
            } else {
                numCounts[A[i]]++;
                numCounts[B[i]]++;
            }
        }
        
        int num = 0;
        for (int i = 1; i < 7; i++) {
            if (numCounts[i] == A.size()) {
                num = i;
                break;
            }
        }
        if (num == 0) {
            return -1;
        }
        
        int count = 0;
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == num && A[i] != B[i]) {
                count++;
            }
            if (A[i] == B[i]) {
                sum++;
            }
        }
        
        return std::min(count, (int)A.size() - count - sum);
    }
};
