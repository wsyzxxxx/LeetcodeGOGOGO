class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = right;
        while (res > left) {
            res &= res-1;
        }
        
        return res;
    }
};