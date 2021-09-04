const long long MOD = 1e9 + 7;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int hasZero = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                hasZero = 1;
                break;
            }
        }
        
        long long zeroEnds = 0;
        long long oneEnds = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                zeroEnds = (zeroEnds + oneEnds) % MOD;
            } else {
                oneEnds = (zeroEnds + oneEnds + 1) % MOD;
            }
        }
        
        return (zeroEnds + oneEnds + hasZero) % MOD;
    }
};