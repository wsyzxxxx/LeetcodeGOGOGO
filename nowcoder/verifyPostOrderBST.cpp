class Solution {
private:
    bool VerifySquenceOfBST(vector<int> & seq, int start, int end) {
        if (start >= end) {
            return true;
        }
        
        int rootVal = seq[end];
        int i = start;
        for (;i < end; i++) {
            if (seq[i] > rootVal) {
                break;
            }
        }
        
        for (int j = i; j < end; j++) {
            if (seq[j] < rootVal) {
                return false;
            }
        }
        
        return VerifySquenceOfBST(seq, start, i-1) &&
               VerifySquenceOfBST(seq, i, end-1);
    }
public:
    bool VerifySquenceOfBST(vector<int> & sequence) {
        if (sequence.empty()) {
            return false;
        }
        
        return VerifySquenceOfBST(sequence, 0, sequence.size()-1);
    }
};
