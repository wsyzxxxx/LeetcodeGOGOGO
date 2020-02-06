class Solution {
private:
    int minRotations(std::vector<int> & A,
                     std::vector<int> & B,
                     int num) {
        int rotateA = 0;
        int rotateB = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == num && B[i] == num) {
                continue;
            } else if (A[i] == num) {
                rotateB++;
            } else if (B[i] == num) {
                rotateA++;
            } else {
                return -1;
            }
        }
        
        return std::min(rotateA, rotateB);
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty() || A.size() != B.size()) {
            return -1;
        }
        
        int rotations = minRotations(A, B, A[0]);
        
        if (rotations == -1) {
            return minRotations(B, A, B[0]);
        } else {
            return rotations;
        }
        
        
    }
};
